#!/bin/sh
set -e # Exit early if any commands fail

PROJECT_DIR="/Users/sakata/main/something/projects/ysh/yshell"

(
  cd "$PROJECT_DIR"
  cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake
  cmake --build ./build
)

exec "$PROJECT_DIR/build/shell" "$@"
