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
        ":string",
        "//latest/base/test:simple_cc_proto",
        "@com_google_googletest//:gtest_main",
    ],
)
