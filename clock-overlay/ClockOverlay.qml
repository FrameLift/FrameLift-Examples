pragma ComponentBehavior: Bound

import QtQuick

// The host instantiates this root and injects the C++ module as `viewModel`.
Item {
    id: root
    required property var viewModel

    // Redraw contract: a hidden surface should do no work. Drive the view-model's
    // timer from visibility so the clock stops ticking while it isn't shown.
    onVisibleChanged: root.viewModel.setActive(root.visible)
    Component.onCompleted: root.viewModel.setActive(root.visible)

    Rectangle {
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 16
        width: clock.implicitWidth + 24
        height: clock.implicitHeight + 12
        radius: 6
        color: "#cc101018"

        Text {
            id: clock
            anchors.centerIn: parent
            text: root.viewModel ? root.viewModel.time : ""
            color: "white"
            font.pixelSize: 20
            font.family: "monospace"
        }
    }
}
