# FrameLift Examples

Worked example plugins for [FrameLift](https://github.com/FrameLift/FrameLift) — a lightweight,
extensible video player where every feature ships as a runtime-loaded **plugin** (a Qt plugin DLL/SO
the host loads at startup). These examples build against the public **FrameLift Plugin SDK** and are a
good starting point to copy from.

> Building a plugin needs only a C++23 compiler, CMake, and Qt 6 — no third-party UI, logging, image,
> or JSON libraries.

## Examples

| Example | What it shows |
|---------|----------------|
| [`hello-plugin/`](hello-plugin/) | The minimal plugin: a single non-rendering module that logs a line on install. Proves the SDK builds a working plugin DLL/SO with no third-party libraries beyond Qt. |
| [`clock-overlay/`](clock-overlay/) | **Rendering.** A corner HUD clock — a QObject view-model (`Q_PROPERTY`/`Q_INVOKABLE`) driving an embedded Qt Quick (QML) root, layered over the video by `renderOrder`, with the hidden-surface redraw contract honored. |
| [`now-playing/`](now-playing/) | **Services & events.** A non-rendering plugin that consumes a host service (`IHistory`), subscribes to and publishes pub/sub events, and registers its own service (`INowPlaying`) for other plugins to query. |

## Building

These examples build against the published SDK, not the FrameLift source tree.

1. Download `FrameLift-sdk-<ver>.zip` from a tagged [FrameLift release](https://github.com/FrameLift/FrameLift/releases)
   and unpack it anywhere.
2. Point `FRAMELIFT_SDK_DIR` at the extracted SDK root and build:

   ```sh
   cmake -B build -DFRAMELIFT_SDK_DIR=/path/to/framelift-sdk-<ver>
   cmake --build build
   # -> build/plugins/framelift.helloplugin.{so,dll}
   ```

   (Alternatively, add the SDK's `cmake/` directory to `CMAKE_PREFIX_PATH` and omit
   `FRAMELIFT_SDK_DIR`.)

Plugin DLLs/SOs are emitted under `build/plugins/` with lowercase artifact names — the artifact is
`publisher.plugin` (here `framelift.helloplugin`).

## Running a built plugin

Drop the resulting plugin DLL/SO into the `plugins/` directory next to the `framelift` executable;
it loads on the next launch. Plugins are enabled by default — to stop one loading, set
`<plugin-id>=disabled` in `plugins.ini` in the FrameLift config directory.

## Learn more

- [FrameLift](https://github.com/FrameLift/FrameLift) — the player and the SDK source.
- [Documentation](https://framelift.santoda.dev) — user guide, build guide, architecture, and the
  full Plugin SDK reference.

## License

[zlib](LICENSE)
