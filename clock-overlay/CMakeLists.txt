# A rendering example plugin. QML_URI + QML_ENTRY register the embedded Qt Quick
# component; add_framelift_plugin builds the QML module and points the host at it.
add_framelift_plugin(ClockOverlay
        PLUGIN_JSON "${CMAKE_CURRENT_SOURCE_DIR}/ClockOverlay.Plugin.json"
        QML_URI Example.Plugins.ClockOverlay
        QML_ENTRY "${CMAKE_CURRENT_SOURCE_DIR}/ClockOverlay.qml"
        "${CMAKE_CURRENT_SOURCE_DIR}/ClockOverlay.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/ClockOverlay.h"
        ${FRAMELIFT_SDK_SOURCES}
)
target_include_directories(ClockOverlay PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
