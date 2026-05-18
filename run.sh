#!/usr/bin/env bash
# run.sh
set -euo pipefail
cmake -S . -B build
cmake --build build --target quake -j
./build/quake "$@"
