load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "tast",
    srcs = ["tast.c"],
    linkopts = ["/SUBSYSTEM:WINDOWS"],
)

cc_binary(
    name = "main",
    srcs = ["main.c",
            "main.h"],
    linkopts = ["/SUBSYSTEM:WINDOWS"],
)

