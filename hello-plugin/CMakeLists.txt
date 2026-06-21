# Example FrameLift plugin. Built standalone against the packaged SDK —
# add_framelift_plugin + the FRAMELIFT_SDK_SOURCES variable come from
# find_package(FrameLiftSdk) (resolved by the repo-root CMakeLists.txt).
add_framelift_plugin(HelloPlugin
        PLUGIN_JSON "${CMAKE_CURRENT_SOURCE_DIR}/HelloPlugin.Plugin.json"
        "${CMAKE_CURRENT_SOURCE_DIR}/core/HelloPlugin.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/core/HelloPlugin.h"
        ${FRAMELIFT_SDK_SOURCES}
)
target_include_directories(HelloPlugin PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/core")
