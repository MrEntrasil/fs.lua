#include <iostream>
#include "functions.hpp"

extern "C" {
    #include <lua5.4/lua.h>
    #include <lua5.4/lauxlib.h>

    int luaopen_fslua(lua_State* L){
        luaL_newlib(L, functions);
        return 1;
    }
}
