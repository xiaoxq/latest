# Third-party integration test.

cc_test(
    name = "third_party_test",
    srcs = ["third_party_test.cc"],
    deps = [
        "@com_google_absl//absl/strings",
        "@com_google_glog//:glog",
        "@com_google_googletest//:gtest_main",
        "@com_google_protobuf//:protobuf",
        "@github_nlohmann_json//:json",
        "//conda:boost_filesystem",
    ],
)
