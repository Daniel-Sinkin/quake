// app/main.cpp
// Internals
#include "quake/quake_app.hpp"
// Externals
// Standard Library
//

auto main(int argc, char** argv) -> int
{
    return ds_vk_quake::run_quake_app(argc, argv);
}
