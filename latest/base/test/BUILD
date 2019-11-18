package(default_visibility = ["//visibility:public"])

load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

proto_library(
    name = "simple_proto",
    srcs = ["simple.proto"],
)

cc_proto_library(
    name = "simple_cc_proto",
    deps = [":simple_proto"],
)
