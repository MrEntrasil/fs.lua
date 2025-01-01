#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

extern "C" {
    #include <lua.h>
    #include <lauxlib.h>
    #include <lualib.h>

    int fs_readfile(lua_State* L){
        std::ostringstream oss;
        std::ifstream file(luaL_checklstring(L, 1, NULL));

        if (!file.is_open()){
            lua_pushnil(L);
        } else {
            oss << file.rdbuf();
            lua_pushstring(L, oss.str().c_str());
        }

        file.close();
        return 1;
    }

    int fs_writefile(lua_State* L){
        std::ofstream file(luaL_checklstring(L, 1, NULL));

        if (!file.is_open()) {
            lua_pushnil(L);
        } else {
            file << luaL_checklstring(L, 2, NULL);
            file.close();
            lua_pushboolean(L, 1);
        }

        return 1;
    }

    static const struct luaL_Reg functions[] = {
        {"readfile", fs_readfile},
        {"writefile", fs_writefile},
        {NULL, NULL}
    };
}