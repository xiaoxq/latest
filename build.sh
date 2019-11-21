#!/usr/bin/env bash

cd "$( dirname "${BASH_SOURCE[0]}" )"

conda env update -f conda/env.yaml -p conda/env --prune

if [ -z "$1" ]; then
  bazel build //...
else
  bazel build $@
fi
