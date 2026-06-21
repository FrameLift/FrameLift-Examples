# FrameLift Examples

Worked example plugins for [FrameLift](https://github.com/FrameLift/FrameLift) — a lightweight,
extensible video player where every feature ships as a runtime-loaded **package** (a DLL the host
loads at startup). These examples build against the public **FrameLift Plugin SDK** and are a good
starting point to copy from.

> The SDK is **dependency-free**: building a plugin needs only a C++23 compiler and CMake — no
> imgui, spdlog, stb, or JSON libraries.

## Examples

| Example | What it shows |
|---------|----------------|
| [`hello-plugin/`](hello-plugin/) | The minimal plugin: a single non-rendering module that logs a line on install. Proves the SDK builds a working package DLL with zero third-party dependencies. |

## Building

These examples build against the published SDK, not the FrameLift source tree.

1. Download `FrameLift-sdk-<ver>.zip` from a tagged [FrameLift release](https://github.com/FrameLift/FrameLift/releases)
   and unpack it anywhere.
2. Point `FRAMELIFT_SDK_DIR` at the extracted SDK root and build:

   ```sh
   cmake -B build -DFRAMELIFT_SDK_DIR=/path/to/framelift-sdk-<ver>
   cmake --build build
   # -> build/packages/framelift.helloplugin.core.{so,dll}
   ```

   (Alternatively, add the SDK's `cmake/` directory to `CMAKE_PREFIX_PATH` and omit
   `FRAMELIFT_SDK_DIR`.)

Package DLLs are emitted under `build/packages/` with lowercase artifact names — a single-module
package is `publisher.package.module` (here `framelift.helloplugin.core`).

## Running a built plugin

Drop the resulting package DLL into the `packages/` directory next to the `framelift` executable;
it loads on the next launch. Every module a package carries is enabled by default — to stop one
loading, set `<module-id>=disabled` in `packages.ini` in the FrameLift config directory.

## Learn more

- [FrameLift](https://github.com/FrameLift/FrameLift) — the player and the SDK source.
- [Documentation](https://framelift.santoda.dev) — user guide, build guide, architecture, and the
  full Plugin SDK reference.

## License

[zlib](LICENSE)
