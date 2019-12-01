workspace(name = "latest")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")

# Common rules with bazel_federation:
# https://github.com/bazelbuild/bazel-federation
http_archive(
    name = "bazel_federation",
    url = "https://github.com/bazelbuild/bazel-federation/archive/130c84ec6d60f31b711400e8445a8d0d4a2b5de8.zip",
    sha256 = "9d4fdf7cc533af0b50f7dd8e58bea85df3b4454b7ae00056d7090eb98e3515cc",
    strip_prefix = "bazel-federation-130c84ec6d60f31b711400e8445a8d0d4a2b5de8",
    type = "zip",
)
load("@bazel_federation//:repositories.bzl", "rules_cc", "rules_python")
rules_cc()
load("@bazel_federation//setup:rules_cc.bzl", "rules_cc_setup")
rules_cc_setup()

rules_python()
load("@bazel_federation//setup:rules_python.bzl", "rules_python_setup")
rules_python_setup()

# Proto rules: https://github.com/bazelbuild/rules_proto
http_archive(
    name = "rules_proto",
    sha256 = "602e7161d9195e50246177e7c55b2f39950a9cf7366f74ed5f22fd45750cd208",
    strip_prefix = "rules_proto-97d8af4dc474595af3900dd85cb3a29ad28cc313",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz",
        "https://github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz",
    ],
)
load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")
rules_proto_dependencies()
rules_proto_toolchains()

# Third party libs.
git_repository(
  name = "com_google_absl",
  remote = "https://github.com/abseil/abseil-cpp",
  tag = "20190808",
)

git_repository(
  name = "com_google_googletest",
  remote = "https://github.com/google/googletest",
  tag = "release-1.10.0",
)

# Note that gflags is only for compiling glog. For your applications please use
# Abseil FLAGS: https://abseil.io/docs/python/guides/flags
git_repository(
  name = "com_github_gflags_gflags",
  remote = "https://github.com/gflags/gflags",
  tag = "v2.2.2",
)

git_repository(
  name = "com_google_glog",
  remote = "https://github.com/google/glog",
  tag = "v0.4.0",
)

new_git_repository(
  name = "com_github_jpbarrette_curlpp",
  remote = "https://github.com/jpbarrette/curlpp",
  tag = "v0.8.1",
  build_file_content = """
cc_library(
    name = "com_github_jpbarrette_curlpp",
    srcs = glob(["src/curlpp/**/*.cpp"]),
    hdrs = glob([
      "include/curlpp/**/*.hpp",
      "include/curlpp/**/*.inl",
    ]),
    includes = ["include"],
    visibility = ["//visibility:public"],
)""",
)

http_archive(
  name = "github_nlohmann_json",
  url = "https://github.com/nlohmann/json/releases/download/v3.7.3/include.zip",
  build_file_content = """
cc_library(
    name = "github_nlohmann_json",
    hdrs = ["single_include/nlohmann/json.hpp"],
    includes = ["single_include"],
    visibility = ["//visibility:public"],
)""",
)
