#pragma once

#include <framelift/core.h>

#include <QtCore/QObject>
#include <QtCore/QString>

class QTimer;

// A minimal *rendering* plugin: a corner HUD clock layered over the video.
//
// It shows the FrameLift rendering model end to end:
//   * a QObject view-model that exposes state to QML via Q_PROPERTY + NOTIFY,
//   * a Q_INVOKABLE the QML calls to honor the redraw contract — the clock ticks
//     only while its surface is visible, so a hidden HUD costs nothing,
//   * an embedded QML root (ClockOverlay.qml) stacked by `renderOrder`.
//
// Because `.qml` defaults to true in the entry macro, the module *is* the view-model
// handed to its QML root as `viewModel`.
class ClockOverlay final : public QObject, public ModuleBase
{
    Q_OBJECT
    Q_PROPERTY(QString time READ Time NOTIFY timeChanged)

public:
    ClockOverlay();

    [[nodiscard]] QString Time() const
    {
        return time_;
    }

    // Called from QML's onVisibleChanged: start ticking when shown, stop when hidden.
    Q_INVOKABLE void setActive(bool active);

Q_SIGNALS:
    void timeChanged();

protected:
    const char* ModuleName() const override
    {
        return "ClockOverlay";
    }

private:
    void Tick();

    QTimer* timer_ = nullptr;
    QString time_;
};

FRAMELIFT_MODULE_ENTRY(ClockOverlay, {
    .renderOrder = 80,
})
