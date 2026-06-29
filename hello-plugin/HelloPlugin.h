#pragma once

#include <framelift/core.h>

// Minimal FrameLift plugin: logs a line on install and registers no UI.
// The smallest plugin that builds against the SDK — one IModule, no QML surface.
class HelloPlugin : public ModuleBase
{
protected:
    const char* ModuleName() const override
    {
        return "HelloPlugin";
    }

    void OnInstall(IModuleContext& ctx) override;
};

FRAMELIFT_MODULE_ENTRY(HelloPlugin, {
    .qml = false,
})
