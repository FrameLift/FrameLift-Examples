#pragma once

#include <framelift/core.h>

#include <string>

// A service this plugin publishes for others to query synchronously. Service
// interfaces are pure abstract classes with POD-only signatures and a unique
// InterfaceId — the same shape as the host's own services (IHistory, …).
class INowPlaying
{
public:
    static constexpr const char* InterfaceId = "example.INowPlaying";
    virtual ~INowPlaying() = default;

    // Copies the current file path into `buf`; returns the length excluding the
    // NUL (pass buf=nullptr to query the size). Empty when nothing is playing.
    [[nodiscard]] virtual int GetCurrent(char* buf, int cap) const noexcept = 0;
};

// A non-rendering plugin that exercises the FrameLift service + event model:
//   * consumes a host service (IHistory) to read a saved resume position,
//   * subscribes to pub/sub events (FileOpenedEvent / FileEndedEvent),
//   * publishes an event (NotificationEvent) the Overlay plugin renders,
//   * registers its OWN service (INowPlaying) for other plugins to query.
//
// It draws nothing, so it opts out of QML with `.qml = false` and stays a plain
// ModuleBase (no QObject needed).
class NowPlaying final : public ModuleBase, public INowPlaying
{
public:
    int GetCurrent(char* buf, int cap) const noexcept override;

protected:
    const char* ModuleName() const override
    {
        return "NowPlaying";
    }

    void OnInstall(IModuleContext& ctx) override;

private:
    std::string current_;
};

FRAMELIFT_MODULE_ENTRY(NowPlaying, {
    .qml = false,
})
