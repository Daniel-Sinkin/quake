cmake_minimum_required(VERSION 3.20)

if(APPLE AND NOT DEFINED CMAKE_C_COMPILER AND NOT DEFINED CMAKE_CXX_COMPILER)
  foreach(DS_TEMPLATE_LLVM_PREFIX IN ITEMS /opt/homebrew/opt/llvm /usr/local/opt/llvm)
    if(EXISTS "${DS_TEMPLATE_LLVM_PREFIX}/bin/clang" AND EXISTS "${DS_TEMPLATE_LLVM_PREFIX}/bin/clang++")
      set(CMAKE_C_COMPILER "${DS_TEMPLATE_LLVM_PREFIX}/bin/clang" CACHE FILEPATH "C compiler" FORCE)
      set(CMAKE_CXX_COMPILER "${DS_TEMPLATE_LLVM_PREFIX}/bin/clang++" CACHE FILEPATH "C++ compiler" FORCE)
      message(STATUS "Using LLVM toolchain from ${DS_TEMPLATE_LLVM_PREFIX}")
      break()
    endif()
  endforeach()
endif()

project(quake LANGUAGES C CXX)

if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type" FORCE)
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(QUAKE_VORBISFILE REQUIRED IMPORTED_TARGET vorbisfile)

add_subdirectory(external/ds-vk)

add_executable(quake
  app/main.cpp
  src/quake/background_music.cpp
  src/quake/io.cpp
  src/quake/mdl.cpp
  src/quake/quake_app.cpp
)

target_include_directories(quake PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_definitions(quake PRIVATE
  DS_VK_ASSET_DIR="${CMAKE_CURRENT_SOURCE_DIR}/local/assets"
  DS_VK_QUAKE_ASSET_DIR="${CMAKE_CURRENT_SOURCE_DIR}/local/assets/quake"
  DS_VK_QUAKE_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/local/source/WinQuake"
)

target_link_libraries(quake PRIVATE
  ds_vk
  ds_vk_viz
  ds_vk_picker
  PkgConfig::QUAKE_VORBISFILE
  ds_vk_warnings
)
