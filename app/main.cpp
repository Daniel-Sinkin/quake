// app/main.cpp
#include "quake/quake_app.hpp"

auto main(int argc, char** argv) -> int
{
    return ds_vk_quake::run_quake_app(argc, argv);
}
