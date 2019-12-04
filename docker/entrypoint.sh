#!/usr/bin/env bash

# Align solo user to the given UID and GID.
sudo groupmod -g "${GID}" aaron
sudo usermod -u "${UID}" -g "${GID}" aaron

mkdir -p /home/aaron/.cache/bazel/_bazel_aaron

bash
