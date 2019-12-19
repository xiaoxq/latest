package(default_visibility = ["//visibility:public"])

genrule(
    name = "cmake_curlpp",
    srcs = glob(["**"]),
    outs = ["libcurlpp.so"],
    cmd = """
        BUILD_DIR=external/com_github_jpbarrette_curlpp/build
        mkdir -p $${BUILD_DIR}
        pushd $${BUILD_DIR}
          cmake .. && cmake --build .
        popd
        cp -L $${BUILD_DIR}/libcurlpp.so $@
    """,
)

cc_library(
    name = "com_github_jpbarrette_curlpp",
    hdrs = glob(["include/**"]),
    srcs = ["libcurlpp.so"],
    strip_include_prefix = "include",
)
