#!/usr/bin/env bash

DOCKER_USER="xiangquan"  # Replace with yours.
REPO="${DOCKER_USER}/latest"
IMAGE="${REPO}:latest"
CONTAINER="latest"

cd $( dirname "${BASH_SOURCE[0]}" )/..

docker inspect -f '{{.State.Running}}' "${CONTAINER}" > /dev/null
if [ $? -ne 0 ]; then
  docker run -it -d --rm --net host --name "${CONTAINER}" \
      -e UID=$(id -u) \
      -e GID=$(id -g) \
      -v $(pwd):/latest \
      "${IMAGE}"
else
  echo "There is already a running *${CONTAINER}* container."
fi
