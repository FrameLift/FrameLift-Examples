#include "NowPlaying.h"

#include <cstring>

void NowPlaying::OnInstall(IModuleContext& ctx)
{
    // Provider side: publish our own service so any plugin can ask what's playing.
    ctx.RegisterService<INowPlaying>(this);

    // React to a file starting. `ctx_` is the context ModuleBase stored for us in
    // Install(), valid for the plugin's whole lifetime.
    framelift::Subscribe<FileOpenedEvent>(
        ctx,
        [this](const FileOpenedEvent& e)
        {
            current_ = e.path ? e.path : "";

            // Consumer side: read the saved resume position from the History
            // plugin. The service is null when History is disabled — always
            // null-check what GetService returns.
            double resume = 0.0;
            if (auto* history = ctx_->GetService<IHistory>())
            {
                resume = history->GetResumePos(current_.c_str());
            }

            if (resume > 0.0)
            {
                Log::Info("[NowPlaying] {} (resume at {:.0f}s)", current_, resume);
            }
            else
            {
                Log::Info("[NowPlaying] {}", current_);
            }

            // Publish an event the Overlay subscribes to and shows on screen. The
            // payload's const char* must stay valid for the synchronous Publish call.
            const std::string text = "Now playing: " + current_;
            ctx_->Publish(NotificationEvent{.text = text.c_str()});
        }
    );

    framelift::Subscribe<FileEndedEvent>(
        ctx,
        [this](const FileEndedEvent&)
        {
            current_.clear();
        }
    );
}

int NowPlaying::GetCurrent(char* buf, const int cap) const noexcept
{
    const int len = static_cast<int>(current_.size());
    if (buf && cap > 0)
    {
        const int n = len < cap - 1 ? len : cap - 1;
        std::memcpy(buf, current_.data(), static_cast<std::size_t>(n));
        buf[n] = '\0';
    }
    return len;
}
