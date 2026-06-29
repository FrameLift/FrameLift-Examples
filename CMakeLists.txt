# Standalone build root for the FrameLift plugin examples.
#
# These examples build against the published FrameLift plugin SDK — the
# framelift-sdk-<ver>.zip archive attached to each tagged FrameLift release.
# Download and unpack it, then point FRAMELIFT_SDK_DIR at the extracted root:
#
#   cmake -B build -DFRAMELIFT_SDK_DIR=/path/to/framelift-sdk-<ver>
#   cmake --build build
#   # -> build/plugins/framelift.helloplugin.{so,dll}
#
# (Alternatively, add the SDK's cmake/ directory to CMAKE_PREFIX_PATH and omit
# FRAMELIFT_SDK_DIR.) Building a plugin needs only a C++23 compiler, CMake, and
# Qt 6 — no third-party UI, logging, image, or JSON library.
cmake_minimum_required(VERSION 3.28)
project(FrameLiftExamples LANGUAGES CXX)

if (DEFINED FRAMELIFT_SDK_DIR)
    find_package(FrameLiftSdk REQUIRED PATHS "${FRAMELIFT_SDK_DIR}/cmake" NO_DEFAULT_PATH)
else ()
    find_package(FrameLiftSdk REQUIRED)
endif ()

add_subdirectory(hello-plugin)
add_subdirectory(clock-overlay)
add_subdirectory(now-playing)
