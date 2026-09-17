#!/usr/bin/env bash

set -euo pipefail

project_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

if [[ -n "${CXX:-}" ]]; then
    compiler="$CXX"
elif [[ -x "/mnt/c/msys64/mingw64/bin/g++.exe" ]]; then
    compiler="/mnt/c/msys64/mingw64/bin/g++.exe"
    mingw_root="/mnt/c/msys64/mingw64"
elif [[ -x "/c/msys64/mingw64/bin/g++.exe" ]]; then
    compiler="/c/msys64/mingw64/bin/g++.exe"
    mingw_root="/c/msys64/mingw64"
else
    compiler="g++"
fi

compiler_options=()
if [[ -n "${mingw_root:-}" ]]; then
    compiler_options+=(
        -I "$mingw_root/include"
        -L "$mingw_root/lib"
    )
fi

if [[ "$compiler" == *.exe && "$(uname -s)" == Linux* ]]; then
    windows_project_dir="$(wslpath -w "$project_dir")"
    windows_compiler="$(wslpath -w "$compiler")"
    powershell.exe -NoProfile -Command \
        "& '$windows_compiler' -std=c++17 '$windows_project_dir/main.cpp' '$windows_project_dir/APIClient.cpp' '$windows_project_dir/parser.cpp' '$windows_project_dir/CLI.cpp' -I '$windows_project_dir/include' -I 'C:\\msys64\\mingw64\\include' -L 'C:\\msys64\\mingw64\\lib' -lcurl -o '$windows_project_dir/wbo-cli.exe'"
else
    "$compiler" \
        -std=c++17 \
        "$project_dir/main.cpp" \
        "$project_dir/APIClient.cpp" \
        "$project_dir/parser.cpp" \
        "$project_dir/CLI.cpp" \
        -I "$project_dir/include" \
        "${compiler_options[@]}" \
        -lcurl \
        -o "$project_dir/wbo-cli.exe"
fi

echo "Build successful: $project_dir/wbo-cli.exe"