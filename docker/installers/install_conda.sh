#!/usr/bin/env bash

pushd $( dirname "${BASH_SOURCE[0]}" )
set -e

# https://docs.conda.io/projects/conda/en/latest/user-guide/install/linux.html
wget "https://repo.continuum.io/miniconda/Miniconda3-latest-Linux-x86_64.sh"
bash Miniconda3-latest-Linux-x86_64.sh -b
rm Miniconda3-latest-Linux-x86_64.sh
echo 'export PATH=/home/aaron/miniconda3/bin:$PATH' > /home/aaron/.bashrc

popd
