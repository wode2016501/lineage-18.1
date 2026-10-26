#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
bp2makefile.py — 把 Android.bp 的 cc_library_* 模块转成标准 GNU Makefile

字段映射：
    name                        → 目标名 / 变量后缀
    srcs                        → SRC_<var>
    include_dirs                → -Ipath  (拼成 INC_<var>)
    cflags                      → CFLAGS_<var>
    cppflags                    → CPPFLAGS_<var>
    ldflags                     → LDFLAGS_<var>
    shared_libs/static_libs/
    whole_static_libs           → -lxxx (拼成 LIBS_<var>)
    cc_library_shared           → libxxx.so（-shared）
    cc_library_static           → libxxx.a（ar rcs）
    all 目标                    → 收集全部产物

用法：
    python3 bp2makefile.py Android.bp makefile
    make -f makefile all
"""

import re
import sys
import json
from pathlib import Path

# ============================================================
# 1. Tokenizer
# ============================================================
TOKEN_RE = re.compile(r'''
    (?P<comment>//[^\n]*|/\*.*?\*/)          # 注释
  | (?P<string>"(?:\\.|[^"\\])*")            # 双引号字符串
  | (?P<bool>true|false)                     # 布尔
  | (?P<number>-?\d+(?:\.\d+)?)              # 数字
  | (?P<ident>[A-Za-z_][A-Za-z0-9_]*)        # 标识符
  | (?P<punct>[{}\[\]:,+=()])                # 标点
  | (?P<ws>\s+)                              # 空白
''', re.VERBOSE | re.DOTALL)


def tokenize(text: str):
    """把源码切成一串 (kind, value)。"""
    pos, out = 0, []
    n = len(text)
    while pos < n:
        m = TOKEN_RE.match(text, pos)
        if not m:
            raise SyntaxError(
                f"Unexpected char at offset {pos}: {text[pos:pos+30]!r}"
            )
        pos = m.end()
        if m.lastgroup in ("ws", "comment"):
            continue
        out.append((m.lastgroup, m.group()))
    return out


# ============================================================
# 2. Blueprint 递归下降解析器
# ============================================================
class BlueprintParser:
    def __init__(self, tokens):
        self.tk = tokens
        self.i = 0

    # --- 基础工具 ---
    def peek(self):
        return self.tk[self.i] if self.i < len(self.tk) else (None, None)

    def next(self):
        tok = self.tk[self.i]
        self.i += 1
        return tok            # 返回 (kind, value)

    def expect(self, value):
        _, v = self.next()
        if v != value:
            raise SyntaxError(f"Expected {value!r}, got {v!r}")

    # --- 顶层：多个 "type { ... }" 块 ---
    def parse(self):
        result = {}
        while self.i < len(self.tk):
            _, mod_type = self.next()          # ← 取值 (第二个元素)
            self.expect("{")
            result.setdefault(mod_type, []).append(self.parse_props())
            self.expect("}")
        return result

    # --- 属性字典 ---
    def parse_props(self):
        props = {}
        while self.peek()[1] != "}":
            _, key = self.next()               # ← 取值 (第二个元素)
            self.expect(":")
            props[key] = self.parse_value()
            if self.peek()[1] == ",":          # 逗号可选
                self.next()
        return props

    # --- 值（支持 "a" + "b" 拼接）---
    def parse_value(self):
        value = self.parse_atom()
        while self.peek()[1] == "+":
            self.next()
            rhs = self.parse_atom()
            if isinstance(value, list) and isinstance(rhs, list):
                value = value + rhs
            elif isinstance(value, str) and isinstance(rhs, str):
                value = value + rhs
            else:
                value = str(value) + str(rhs)
        return value

    def parse_atom(self):
        kind, val = self.next()

        if kind == "string":
            return json.loads(val)             # 自动处理转义
        if kind == "bool":
            return val == "true"
        if kind == "number":
            return float(val) if "." in val else int(val)

        if val == "[":
            items = []
            while self.peek()[1] != "]":
                items.append(self.parse_value())
                if self.peek()[1] == ",":
                    self.next()
            self.expect("]")
            return items

        if val == "{":
            d = self.parse_props()
            self.expect("}")
            return d

        if kind == "ident":
            # 形如 select(...) / soong_config_variable(...) 的函数调用：保留原文
            if self.peek()[1] == "(":
                depth = 0
                buf = [val]
                while True:
                    _, v = self.next()
                    buf.append(v)
                    if v == "(":
                        depth += 1
                    elif v == ")":
                        depth -= 1
                        if depth == 0:
                            break
                return " ".join(buf)
            return val                          # 例如 true/false/未加引号的标识

        raise SyntaxError(f"Unexpected token: kind={kind}, value={val!r}")


def parse_blueprint(text: str):
    return BlueprintParser(tokenize(text)).parse()


# ============================================================
# 3. bp → Makefile
# ============================================================
# 模块类型 → 产物类型
BUILD_TPL = {
    "cc_library_shared":       "so",
    "cc_library_static":       "a",
    "cc_library":              "a",       # 简化：默认静态
    "cc_library_host_shared":  "so",
    "cc_library_host_static":  "a",
}


def norm(v):
    """把 list / bool / scalar 统一转成 Makefile 里能用的字符串。"""
    if isinstance(v, list):
        return " ".join(str(x) for x in v)
    if isinstance(v, bool):
        return "true" if v else "false"
    return str(v)


def emit_module(m_type: str, m: dict,aos, outdir: str = "build"):
    """生成一个模块的 Makefile 片段，返回 (lines, target_or_None)。"""
    name = m.get("name")
    if not name:
        return [f"# 跳过无 name 的 {m_type}: keys={list(m.keys())}"], None

    var = re.sub(r"\W", "_", name)

    srcs    = m.get("srcs", [])
    incs    = m.get("include_dirs", [])
    cflags  = m.get("cflags", [])
    cppflg  = m.get("cppflags", [])
    shared  = m.get("shared_libs", [])
    static  = m.get("static_libs", [])
    whole   = m.get("whole_static_libs", [])
    ldflags = m.get("ldflags", [])

    # include_dirs → -Ipath
    inc_flags = " ".join(f"-I{aos}/{p}" for p in incs)

    # shared_libs + static_libs + whole_static_libs → -lxxx
    lib_flags = " ".join(f"-l{x}" for x in shared + static + whole)

    # whole_static_libs 的等价语义提示
    whole_note = ""
    if whole:
        w = " ".join(f"-l{x}" for x in whole)
        whole_note = (
            "# NOTE: whole_static_libs 正确语义应为：\n"
            f"#       -Wl,--whole-archive {w} -Wl,--no-whole-archive\n"
        )

    L = []
    L.append(f"# ======== {name}  ({m_type}) ========")
    L.append(f"SRC_{var}      := {norm(srcs)}")
    L.append(f"INC_{var}      := {inc_flags}")
    L.append(f"CFLAGS_{var}   := {norm(cflags)} $(INC_{var})")
    L.append(f"CPPFLAGS_{var} := {norm(cppflg)}")
    L.append(f"LDFLAGS_{var}  := {norm(ldflags)}")
    L.append(f"LIBS_{var}     := {lib_flags}")
    L.append(
        f"OBJ_{var}      := $(patsubst %.cc,{outdir}/{var}/%.o,"
        f"$(patsubst %.c,{outdir}/{var}/%.o,$(SRC_{var})))"
    )
    if whole_note:
        L.append(whole_note.rstrip())
    L.append("")

    # 编译规则：每个模块独立 outdir，避免不同模块同名 .cc 冲突
    L.append(f"{outdir}/{var}/%.o: %.cc")
    L.append("\t@mkdir -p $(dir $@)")
    L.append(f"\t$(CXX) $(CFLAGS_{var}) $(CPPFLAGS_{var}) -c $< -o $@")
    L.append("")

    L.append(f"{outdir}/{var}/%.o: %.c")
    L.append("\t@mkdir -p $(dir $@)")
    L.append(f"\t$(CXX) $(CFLAGS_{var}) $(CPPFLAGS_{var}) -c $< -o $@")
    L.append("")

    # 链接/打包规则
    kind = BUILD_TPL.get(m_type)
    tgt = None
    if kind == "so":
        tgt = f"{name}.so"
        L.append(f"{tgt}: $(OBJ_{var})")
        L.append(f"\t$(CXX) $(LDFLAGS_{var}) -shared -o $@ $^ $(LIBS_{var})")
    elif kind == "a":
        tgt = f"{name}.a"
        L.append(f"{tgt}: $(OBJ_{var})")
        L.append("\t$(AR) rcs $@ $^")
    else:
        L.append(f"# 未处理的模块类型: {m_type} (name={name})")
    L.append("")
    return L, tgt


def generate(bp: dict, out_path: str,aos: str):
    head = [
        "# Auto-generated from Android.bp — 由 bp2makefile.py 生成",
        "# 注意：include_dirs 为 AOSP 相对路径；单独 make 时请修改为实际路径",
        "",
        "CXX ?= g++",
        "AR  ?= ar",
        "",
    ]

    body, targets, skipped = [], [], []

    for m_type, mods in bp.items():
        for m in mods:
            if m_type not in BUILD_TPL:
                label = f"{m_type}/{m.get('name', '<无>')}"
                skipped.append(label)
                body.append(f"# (跳过非 cc_library 类型: {label})")
                continue
            lines, t = emit_module(m_type, m,aos)
            body.extend(lines)
            if t:
                targets.append(t)

    if skipped:
        print("⚠️  跳过:", ", ".join(skipped))

    tail = [
        f"all: {' '.join(targets)}",
        "",
        "clean:",
        "\trm -rf build *.so *.a",
        "",
        ".PHONY: all clean",
        "",
    ]

    Path(out_path).write_text("\n".join(head + body + tail), encoding="utf-8")
    print(f"✅ 生成 {out_path}   目标: {', '.join(targets) or '(无)'}")


# ============================================================
# 4. 入口
# ============================================================
def main(argv):
    src = "Android.bp"
    dst = "Makefile"
    aos = argv[1] if len(argv) > 1 else "/media/wode/3ae32a44-af73-46a8-9aec-c24e84273ebd/test/lineage-17.1"

    src_path = Path(src)
    if not src_path.exists():
        print(f"❌ 找不到输入文件: {src}")
        return 1

    text = src_path.read_text(encoding="utf-8")
    print(f"📖 解析 {src}  ({len(text)} 字节) ...")

    try:
        bp = parse_blueprint(text)
    except SyntaxError as e:
        print(f"❌ 解析失败: {e}")
        return 2

    print(f"   模块类型: {list(bp.keys())}")
    for mt, mods in bp.items():
        for m in mods:
            print(f"   - {mt:20s} name={m.get('name', '<无>')}")

    generate(bp, dst,aos)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
