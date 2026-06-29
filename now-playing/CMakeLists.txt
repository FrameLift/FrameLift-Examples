# A non-rendering example plugin: it talks to the host and other plugins purely
# through services and the pub/sub event bus, so it needs no QML.
add_framelift_plugin(NowPlaying
        PLUGIN_JSON "${CMAKE_CURRENT_SOURCE_DIR}/NowPlaying.Plugin.json"
        "${CMAKE_CURRENT_SOURCE_DIR}/NowPlaying.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/NowPlaying.h"
        ${FRAMELIFT_SDK_SOURCES}
)
target_include_directories(NowPlaying PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
