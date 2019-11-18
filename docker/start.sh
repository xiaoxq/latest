#!/usr/bin/env bash

DOCKER_USER="local"
REPO="${DOCKER_USER}/latest"
IMAGE="${REPO}:latest"
CONTAINER="latest"

cd $( dirname "${BASH_SOURCE[0]}" )/..

docker rm -f "${CONTAINER}" >/dev/null 2>&1
docker run --gpus all -it -d --rm --net host --name "${CONTAINER}" \
    -e UID=$(id -u) \
    -e GID=$(id -g) \
    -v $(pwd):/latest \
    "${IMAGE}"

exec ./docker/login.sh
