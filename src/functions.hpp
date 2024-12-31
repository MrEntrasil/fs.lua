#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

extern "C" {
    #include <lua.h>
    #include <lauxlib.h>
    #include <lualib.h>

    int readfile(lua_State* L){
        const char* param1 = luaL_checklstring(L, 1, NULL);
        std::ostringstream oss;
        std::fstream file(param1);

        if (!file.is_open()){
            lua_pushnil(L);
        } else {
            oss << file.rdbuf();
            lua_pushstring(L, oss.str().c_str());
        }

        return 1;
    }

    static const struct luaL_Reg functions[] = {
        {"readfile", readfile},
        {NULL, NULL}
    };
}