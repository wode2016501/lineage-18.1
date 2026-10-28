#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
bp2makefile.py — 把 Android.bp 转成标准 GNU Makefile

支持：
  * 顶层变量赋值     subdirs = [...]
  * 变量引用         cflags: hidl_flags
  * 模块块           cc_library_shared { ... }
  * 字符串拼接       "a" + "b"
  * 注释             // 和 /* */
  * 值类型           字符串/数字/布尔/列表/字典/select(...)
  * 源文件后缀       .c  .cc  .cpp  .yy  .ll  .S
  * 模块类型         cc_library_shared / cc_library_static / cc_library
                     cc_library_host_shared / cc_library_host_static
                     cc_binary / cc_binary_host

用法：
    python3 bp2makefile.py Android.bp Makefile
    make -f Makefile
"""

import re
import sys
import json
from pathlib import Path

# ============================================================
# 1. Tokenizer
# ============================================================
TOKEN_RE = re.compile(r'''
    (?P<comment>//[^\n]*|/\*.*?\*/)
  | (?P<string>"(?:\\.|[^"\\])*")
  | (?P<bool>true|false)
  | (?P<number>-?\d+(?:\.\d+)?)
  | (?P<ident>[A-Za-z_][A-Za-z0-9_]*)
  | (?P<punct>[{}\[\]:,+=;()])
  | (?P<ws>\s+)
''', re.VERBOSE | re.DOTALL)


def tokenize(text):
    pos, out, n = 0, [], len(text)
    while pos < n:
        m = TOKEN_RE.match(text, pos)
        if not m:
            raise SyntaxError(f"Unexpected char at {pos}: {text[pos:pos+30]!r}")
        pos = m.end()
        if m.lastgroup in ("ws", "comment"):
            continue
        out.append((m.lastgroup, m.group()))
    return out


# ============================================================
# 2. Blueprint 解析器
# ============================================================
class BlueprintParser:
    def __init__(self, tokens):
        self.tk = tokens
        self.i = 0
        self.vars = {}

    def peek(self):
        return self.tk[self.i] if self.i < len(self.tk) else (None, None)

    def next(self):
        tok = self.tk[self.i]
        self.i += 1
        return tok

    def expect(self, value):
        _, v = self.next()
        if v != value:
            raise SyntaxError(f"Expected {value!r}, got {v!r}")

    def parse(self):
        modules = {}
        while self.i < len(self.tk):
            _, key = self.next()
            _, nv = self.peek()
            if nv == "=":                    # 顶层变量
                self.next()
                self.vars[key] = self.parse_value()
                if self.peek()[1] == ";":
                    self.next()
            elif nv == "{":                  # 模块块
                self.next()
                modules.setdefault(key, []).append(self.parse_props())
                self.expect("}")
            else:
                raise SyntaxError(f"Unexpected after {key!r}: {nv!r}")
        return modules

    def parse_props(self):
        props = {}
        while self.peek()[1] != "}":
            _, key = self.next()
            self.expect(":")
            props[key] = self.parse_value()
            if self.peek()[1] == ",":
                self.next()
        return props

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
            return json.loads(val)
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
            if self.peek()[1] == "(":        # select(...) 等函数调用保留原文
                depth, buf = 0, [val]
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
            if val in self.vars:             # 变量引用
                return self.vars[val]
            return val

        raise SyntaxError(f"Unexpected token: kind={kind}, value={val!r}")


def parse_blueprint(text):
    return BlueprintParser(tokenize(text)).parse()


# ============================================================
# 3. bp → Makefile
# ============================================================
BUILD_TPL = {
    "cc_library_shared":       "so",
    "cc_library_static":       "a",
    "cc_library":              "a",
    "cc_library_host_shared":  "so",
    "cc_library_host_static":  "a",
    "cc_binary_host":          "bin",
    "cc_binary":               "bin",
}

# 源文件后缀 → 编译方式
C_SUFFIXES = (".c", ".S")
CXX_SUFFIXES = (".cc", ".cpp", ".cxx", ".C")
GEN_SUFFIXES = (".yy", ".ll")


def norm(v):
    if isinstance(v, list):
        return " ".join(str(x) for x in v)
    if isinstance(v, bool):
        return "true" if v else "false"
    return str(v)


def _is_clean(p):
    return (isinstance(p, str) and p
            and not any(c in p for c in "=+ \t\"'"))


def _obj_expr(var, outdir):
    """构造 OBJ_<var>：把各种后缀的 .c/.cc/.cpp 统一映射到 .o。"""
    # 用嵌套 patsubst：从最内层 c → cc → cpp → yy → ll
    expr = f"$(SRC_{var})"
    for suf in (".cc", ".cpp", ".cxx", ".C"):
        expr = f"$(patsubst %{suf},{outdir}/{var}/%.o,{expr})"
    expr = f"$(patsubst %.c,{outdir}/{var}/%.o,{expr})"
    # .yy / .ll 生成 .cpp 再进 .o 的链路由下面规则处理（暂时只保留 .cpp 上游）
    return expr


def emit_module(m_type, m, outdir="build"):
    name = m.get("name")
    if not name:
        return [f"# 跳过无 name 的 {m_type}: keys={list(m.keys())}"], None

    var = re.sub(r'\W', '_', name)

    srcs     = m.get("srcs", [])
    incs     = list(m.get("include_dirs", []))
    incs    += m.get("local_include_dirs", [])
    incs    += m.get("export_include_dirs", [])
    cflags   = m.get("cflags", [])
    cppflg   = m.get("cppflags", [])
    shared   = m.get("shared_libs", [])
    static   = m.get("static_libs", [])
    whole    = m.get("whole_static_libs", [])
    ldflags  = m.get("ldflags", [])

    clean_incs = []
    for p in incs:
        if _is_clean(p):
            if p not in clean_incs:
                clean_incs.append(p)
        else:
            print(f"⚠️  跳过非法 include_dir: {p!r}")
    inc_flags = " ".join(f"-I{p}" for p in clean_incs)

    clean_libs = []
    for x in shared + static + whole:
        if _is_clean(x):
            if x not in clean_libs:
                clean_libs.append(x)
        else:
            print(f"⚠️  跳过非法 lib: {x!r}")
    lib_flags = " ".join(f"-l{x}" for x in clean_libs)

    whole_note = ""
    if whole:
        w = " ".join(f"-l{x}" for x in whole if _is_clean(x))
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
    L.append(f"OBJ_{var}      := {_obj_expr(var, outdir)}")
    if whole_note:
        L.append(whole_note.rstrip())
    L.append("")

    # 编译规则
    L.append(f"{outdir}/{var}/%.o: %.cc")
    L.append("\t@mkdir -p $(dir $@)")
    L.append(f"\t$(CXX) $(CFLAGS_{var}) $(CPPFLAGS_{var}) -c $< -o $@")
    L.append("")

    L.append(f"{outdir}/{var}/%.o: %.cpp")
    L.append("\t@mkdir -p $(dir $@)")
    L.append(f"\t$(CXX) $(CFLAGS_{var}) $(CPPFLAGS_{var}) -c $< -o $@")
    L.append("")

    L.append(f"{outdir}/{var}/%.o: %.cxx")
    L.append("\t@mkdir -p $(dir $@)")
    L.append(f"\t$(CXX) $(CFLAGS_{var}) $(CPPFLAGS_{var}) -c $< -o $@")
    L.append("")

    L.append(f"{outdir}/{var}/%.o: %.c")
    L.append("\t@mkdir -p $(dir $@)")
    L.append(f"\t$(CXX) $(CFLAGS_{var}) $(CPPFLAGS_{var}) -c $< -o $@")
    L.append("")

    L.append(f"{outdir}/{var}/%.o: %.S")
    L.append("\t@mkdir -p $(dir $@)")
    L.append(f"\t$(CXX) $(CFLAGS_{var}) $(CPPFLAGS_{var}) -c $< -o $@")
    L.append("")

    # flex / bison（.yy → .cpp, .ll → .cpp）
    L.append("%.cpp: %.yy")
    L.append("\t@mkdir -p $(dir $@)")
    L.append("\t$(BISON) --defines=/dev/null -o $@ $<")
    L.append("")

    L.append("%.cpp: %.ll")
    L.append("\t@mkdir -p $(dir $@)")
    L.append("\t$(FLEX) -o $@ $<")
    L.append("")

    # 产物
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
    elif kind == "bin":
        tgt = name
        L.append(f"{tgt}: $(OBJ_{var})")
        L.append(f"\t$(CXX) $(LDFLAGS_{var}) -o $@ $^ $(LIBS_{var})")
    else:
        L.append(f"# 未处理的模块类型: {m_type} (name={name})")
    L.append("")
    return L, tgt


def generate(bp, out_path):
    head = [
        "# Auto-generated from Android.bp — 由 bp2makefile.py 生成",
        "# 注意：include_dirs 为 AOSP 相对路径；单独 make 时请改成实际路径",
        "",
        ".DEFAULT_GOAL := all",
        "",
        "CXX   ?= g++",
        "AR    ?= ar",
        "FLEX  ?= flex",
        "BISON ?= bison",
        "",
    ]

    body, targets, skipped = [], [], []
    for m_type, mods in bp.items():
        for m in mods:
            if m_type not in BUILD_TPL:
                label = f"{m_type}/{m.get('name', '<无>')}"
                skipped.append(label)
                body.append(f"# (跳过非 cc_library/cc_binary 类型: {label})")
                continue
            lines, t = emit_module(m_type, m)
            body.extend(lines)
            if t:
                targets.append(t)

    if skipped:
        print("⚠️  跳过:", ", ".join(skipped))

    tail = [
        f"all: {' '.join(targets)}",
        "",
        "clean:",
        "\trm -rf build *.so *.a $(filter-out %.sh %.py,$(ALL_BINS))",
        "\trm -f " + " ".join(t for t in targets if "." not in t),
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
    src = argv[1] if len(argv) > 1 else "Android.bp"
    dst = argv[2] if len(argv) > 2 else "Makefile"

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
            print(f"   - {mt:24s} name={m.get('name', '<无>')}")

    generate(bp, dst)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
