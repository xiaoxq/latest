#!/usr/bin/env bash

cd "$( dirname "${BASH_SOURCE[0]}" )"

if [ -z "$1" ]; then
  bazel build //...
else
  bazel build $@
fi
