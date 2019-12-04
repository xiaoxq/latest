package(default_visibility = ["//visibility:public"])

cc_library(
    name = "string",
    srcs = ["string.cc"],
    hdrs = ["string.h"],
    deps = [
        "@com_google_absl//absl/strings",
        "@com_google_protobuf//:protobuf",
    ],
)

cc_test(
    name = "string_test",
    srcs = ["string_test.cc"],
    deps = [
        ":simple_test_cc_proto",
        ":string",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "http_client",
    srcs = ["http_client.cc"],
    hdrs = ["http_client.h"],
    deps = [
        "@com_google_glog//:glog",
        "@curlpp",
        "@github_nlohmann_json",
    ],
)

load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

proto_library(
    name = "simple_test_proto",
    srcs = ["simple_test.proto"],
)

cc_proto_library(
    name = "simple_test_cc_proto",
    deps = [":simple_test_proto"],
)
