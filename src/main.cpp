#include <iostream>
#include "functions.hpp"

extern "C" {
    #include <lua/lua.h>
    #include <lua/lauxlib.h>

    int luaopen_fslua(lua_State* L){
        luaL_register(L, "fslua", functions);
        return 1;
    }
}
