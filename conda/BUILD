package(default_visibility = ["//visibility:public"])

# Just some examples. Compose your own target if needed.
cc_library(
    name = "boost_common",
    hdrs = glob([
        "env/include/boost/*.h",
        "env/include/boost/*.hpp",
        "env/include/boost/predef/**/*.h",
        "env/include/boost/io/**/*.hpp",
        "env/include/boost/type_traits/**/*.hpp",
        "env/include/boost/core/**/*.hpp",
        "env/include/boost/config/**/*.hpp",
        "env/include/boost/detail/**/*.hpp",
        "env/include/boost/utility/**/*.hpp",
        "env/include/boost/iterator/**/*.hpp",
        "env/include/boost/mpl/**/*.hpp",
        "env/include/boost/preprocessor/**/*.hpp",
        "env/include/boost/smart_ptr/**/*.hpp",
        "env/include/boost/exception/**/*.hpp",
        "env/include/boost/container_hash/**/*.hpp",
        "env/include/boost/functional/**/*.hpp",
        "env/include/boost/range/**/*.hpp",
    ]),
)

cc_library(
    name = "boost_system",
    srcs = ["env/lib/libboost_system.a"],
    hdrs = glob([
        "env/include/boost/system/**/*.hpp",
    ]),
    deps = [
        ":boost_common",
    ],
)

cc_library(
    name = "boost_filesystem",
    srcs = ["env/lib/libboost_filesystem.a"],
    hdrs = glob([
        "env/include/boost/filesystem.hpp",
        "env/include/boost/filesystem/**/*.hpp",
    ]),
    includes = ["env/include"],
    deps = [
        ":boost_common",
        ":boost_system",
    ],
)
