#!/usr/bin/env bash

pushd $( dirname "${BASH_SOURCE[0]}" )
set -e

# https://docs.bazel.build/versions/master/install-ubuntu.html
VERSION="1.2.1"
INSTALLER="bazel-${VERSION}-installer-linux-x86_64.sh"

apt install -y pkg-config zip g++ zlib1g-dev unzip python3
wget "https://github.com/bazelbuild/bazel/releases/download/${VERSION}/${INSTALLER}"
bash "${INSTALLER}"
rm "${INSTALLER}"
echo "source /usr/local/lib/bazel/bin/bazel-complete.bash" >> /home/aaron/.bashrc

popd
