// src/quake/background_music.hpp
#pragma once

// Internals
// Externals
#include <SDL3/SDL.h>
#include "ds_vk/types.hpp"
// Standard Library
#include <cstddef>
#include <filesystem>
#include <optional>
#include <vector>
//

namespace dans::app::quake
{
class BackgroundMusic
{
  public:
    BackgroundMusic() = default;
    BackgroundMusic(const BackgroundMusic&) = delete;
    auto operator=(const BackgroundMusic&) -> BackgroundMusic& = delete;

    BackgroundMusic(BackgroundMusic&&) noexcept;
    auto operator=(BackgroundMusic&&) noexcept -> BackgroundMusic&;
    ~BackgroundMusic();

    [[nodiscard]] static auto load_looped_ogg(const std::filesystem::path&, ds_vk::f32 gain)
        -> std::optional<BackgroundMusic>;

    auto pump() -> void;

  private:
    auto reset() -> void;

    SDL_AudioSpec spec_{};
    std::vector<std::byte> pcm_{};
    SDL_AudioStream* stream_{};
    ds_vk::usize cursor_{};
    bool owns_audio_subsystem_{};
};
}  // namespace dans::app::quake
