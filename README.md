# Latest

Latest all-in-one infra code base. Current stack:

- Ubuntu 18.04
- Bazel 1.1
- C++ 17
- Abseil 20190808
- Gtest 1.10
  - Protobuf 3.9
- Nlohmann Json 3.7.3
- Glog 0.4
  - Gflags 2.2.2 (It's required by glog. For your app please use Abseil FLAGS.)

## Prerequisites

### Without Docker

1. Install [bazel](https://bazel.build).

### With Docker

1. Install [Docker CE 19.03+](https://docs.docker.com/install).
1. Install [Nvidia-container-toolkit](https://github.com/NVIDIA/nvidia-docker),
   if you need to use GPU.
1. [Build image](docker/build.sh).
1. [Run container](docker/start.sh).
1. [Login to a running container](docker/login.sh).

## Play

```
bazel build //...
bazel test //...
```
