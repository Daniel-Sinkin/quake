<!-- README.md -->
# Quake Vulkan Viewer

Standalone Quake model viewer using `ds-vk`, fetched by CMake from `git@github.com:Daniel-Sinkin/ds-vk.git` and pinned to commit `c8fd46f192aefbdd06572e93f9228e9b5f40c374`.

The migrated Quake data lives under ignored `local/assets/quake` so this repo can build locally without redistributing game assets. The optional Quake source checkout used for MDL normal dumping belongs at `local/source/WinQuake`.

```sh
cmake -S . -B build
cmake --build build --target quake -j
./build/quake --smoke-frames 1 --hide-ui
```
