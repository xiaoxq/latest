#!/usr/bin/env bash

DOCKER_USER="xiangquan"  # Replace with yours.
REPO="${DOCKER_USER}/latest"
IMAGE="${REPO}:$(date +%Y%m%d_%H%M)"
ALIAS="${REPO}:latest"

echo "Building image: ${IMAGE}"

cd $( dirname "${BASH_SOURCE[0]}" )

docker build -t ${IMAGE} --network host . && \
docker tag ${IMAGE} ${ALIAS}
docker push ${IMAGE}
docker push ${ALIAS}
