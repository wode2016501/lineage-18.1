#! /bin/bash
OUT_DIR=out_headers_dir/proto
cmd=protoc
which aprotoc &&cmd=aprotoc
mkdir -p "$OUT_DIR"
find . -name "*.proto" |while read a;do
	"$cmd" --proto_path=. --cpp_out="$OUT_DIR" "$a"
done
