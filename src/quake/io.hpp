// src/quake/io.hpp
#pragma once

// Internals
// Externals
// Standard Library
#include <cstddef>
#include <filesystem>
#include <optional>
#include <vector>
//

namespace dans::app::quake
{
[[nodiscard]] auto load_binary_file(const std::filesystem::path&)
    -> std::optional<std::vector<std::byte>>;
}  // namespace dans::app::quake
