# Latest

Latest all-in-one infra code base. Current stack:

- Ubuntu 18.04
- Bazel 2.0
- C++ 17
- abseil 20190808
- gtest 1.10
  - Protobuf 3.9
- Nlohmann Json 3.7.3
- glog 0.4
  - gflags 2.2.2 (It's required by glog. For your app please use
    [Abseil FLAGS](https://abseil.io/docs/python/guides/flags).)
- Boost 1.68
- curlpp 0.8.1
- Poco 1.9.4

I try to keep everything up-to-date. Please create an issue if you find newer
stable versions.

## Prerequisites

1. Install [Bazel](https://bazel.build). If you are using the same version of
   Ubuntu, you can try the script:

   ```
   sudo bash docker/installers/install_bazel.sh
   ```

## Play with C++

```bash
bazel build //...
bazel test //...
```
