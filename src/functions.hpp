#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include "file.hpp"
#include "dir.hpp"

extern "C" {
    #include <lua/lua.h>
    #include <lua/lualib.h>
    #include <lua/lauxlib.h>

    static const struct luaL_Reg functions[] = {
        {"readfile", fs_readfile},
        {"writefile", fs_writefile},
        {"exists", fs_exists},
        {"readdir", fs_readdir},
        {"getline", fs_getline},
        {"writedir", fs_writedir},
        {"sizeof", fs_filesize},
        {NULL, NULL}
    };
}
