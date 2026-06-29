#include "ClockOverlay.h"

#include <QtCore/QTime>
#include <QtCore/QTimer>

ClockOverlay::ClockOverlay()
{
    // Parented to `this`, so Qt destroys the timer with the module.
    timer_ = new QTimer(this);
    timer_->setInterval(1000);
    QObject::connect(timer_, &QTimer::timeout, this, &ClockOverlay::Tick);
    Tick();
}

void ClockOverlay::setActive(const bool active)
{
    if (active)
    {
        Tick();
        timer_->start();
    }
    else
    {
        timer_->stop();
    }
}

void ClockOverlay::Tick()
{
    const QString now = QTime::currentTime().toString("HH:mm:ss");
    if (now == time_)
    {
        return;
    }
    time_ = now;
    Q_EMIT timeChanged();
}
