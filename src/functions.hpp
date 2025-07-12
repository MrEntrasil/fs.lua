#pragma once
#include <iostream>
#include "file.hpp"
#include "dir.hpp"

extern "C" {
    #include <lua5.4/lua.h>
    #include <lua5.4/lualib.h>
    #include <lua5.4/lauxlib.h>

    static const struct luaL_Reg functions[] = {
        {"readfile", fs_readfile},
        {"writefile", fs_writefile},
        {"exists", fs_exists},
        {"readdir", fs_readdir},
        {"getline", fs_getline},
        {"writedir", fs_writedir},
        {"sizeof", fs_filesize},
        {"rm", fs_deletefile},
	{"chdir", fs_chdir},
        {NULL, NULL}
    };
}
