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
- Boost 1.68
- curlpp 0.8.1

I try to keep everything up-to-date. Please create an issue if you find newer
stable versions.

## Prerequisites

1. Install [bazel](https://bazel.build).

## Play with C++

```bash
bazel build //...
bazel test //...
```
