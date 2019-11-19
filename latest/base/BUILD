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

cc_test(
    name = "json_test",
    srcs = ["json_test.cc"],
    deps = [
        "@github_nlohmann_json//:json",
        "@com_google_googletest//:gtest_main",
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
