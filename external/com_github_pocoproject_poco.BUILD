package(default_visibility = ["//visibility:public"])

# Here I only show how to build the Foundation target. You may extend to others.
genrule(
    name = "cmake_poco",
    srcs = glob(["**"]),
    outs = ["libPocoFoundation.so"],
    cmd = """
        BUILD_DIR=external/com_github_pocoproject_poco/build
        mkdir -p $${BUILD_DIR}
        pushd $${BUILD_DIR}
          cmake .. && cmake --build . --target Foundation
        popd
        cp -L $${BUILD_DIR}/lib/libPocoFoundation.so $@
    """,
)

cc_library(
    name = "PocoFoundation",
    srcs = ["libPocoFoundation.so"],
    hdrs = glob(["Foundation/include/**/*.h"]),
    includes = ["Foundation/include"],
    strip_include_prefix = "Foundation/include",
)
