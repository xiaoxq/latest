#!/usr/bin/env bash

CONTAINER="latest"

docker inspect -f '{{.State.Running}}' "${CONTAINER}" > /dev/null
if [ $? -ne 0 ]; then
  bash $( dirname "${BASH_SOURCE[0]}" )/start.sh
fi

docker exec -it "${CONTAINER}" bash -c -- "
  source /home/aaron/.bashrc
  set -x
  bazel build //...
  bazel test //...
"
