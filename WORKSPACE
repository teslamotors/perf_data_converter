load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# bazel_skylib is a dependency of protobuf; this declaration must come before
# protobuf to override its internally-declared version.
http_archive(
    name = "bazel_skylib",
    urls = ["https://github.com/bazelbuild/bazel-skylib/releases/download/1.0.3/bazel-skylib-1.0.3.tar.gz"],
    sha256 = "1c531376ac7e5a180e0237938a2536de0c54d93f5c278634818e0efc952dd56c",
)

# GoogleTest/GoogleMock framework. Used by most unit-tests.
http_archive(
     name = "com_google_googletest",
     urls = ["https://github.com/google/googletest/archive/master.zip"],
     strip_prefix = "googletest-master",
)

# rules_python is a dependency for protobuf.
http_archive(
    name = "rules_python",
    url = "https://github.com/bazelbuild/rules_python/releases/download/0.3.0/rules_python-0.3.0.tar.gz",
    sha256 = "934c9ceb552e84577b0faf1e5a2f0450314985b4d8712b2b70717dc679fdc01b",
)

# proto_library, cc_proto_library, and java_proto_library rules implicitly
# depend on @com_google_protobuf for protoc and proto runtimes.
http_archive(
    name = "com_google_protobuf",
    urls = ["https://github.com/protocolbuffers/protobuf/archive/master.zip"],
    strip_prefix = "protobuf-master",
)

http_archive(
    name = "boringssl",  # Must match upstream workspace name.
    # Gitiles creates gzip files with an embedded timestamp, so we cannot use
    # sha256 to validate the archives.  We must rely on the commit hash and
    # https. Commits must come from the master-with-bazel branch.
    urls = ["https://github.com/google/boringssl/archive/master-with-bazel.zip"],
    strip_prefix = "boringssl-master-with-bazel",
)

# zlib is a dependency of protobuf.
http_archive(
    name = "zlib",
    sha256 = "c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1",
    # This is the zlib BUILD file used in kythe:
    # https://github.com/kythe/kythe/blob/v0.0.30/third_party/zlib.BUILD
    build_file = "zlib.BUILD",
    urls = ["https://www.zlib.net/zlib-1.2.11.tar.gz"],
    strip_prefix = "zlib-1.2.11",
)

http_archive(
    name   = "com_github_gflags_gflags",
    urls = ["https://github.com/gflags/gflags/archive/master.zip"],
    strip_prefix = "gflags-master",
)

http_archive(
    name = "com_google_re2",
    urls = ["https://github.com/google/re2/archive/master.zip"],
    strip_prefix = "re2-master",
)
