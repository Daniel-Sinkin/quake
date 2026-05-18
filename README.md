# Quake Vulkan Viewer

Standalone Quake model viewer using `ds-vk` as a git submodule in `external/ds-vk`.

The migrated Quake data lives under ignored `local/assets/quake` so this repo can build locally without redistributing game assets. The optional Quake source checkout used for MDL normal dumping belongs at `local/source/WinQuake`.

```sh
git submodule update --init --recursive
cmake -S . -B build
cmake --build build --target quake -j
./build/quake --smoke-frames 1 --hide-ui
```
