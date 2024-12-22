extern "C" {
    #include <lua.h>
    #include <lauxlib.h>

    int teste(lua_State* L){
        lua_pushstring(L, "Teste");
        return 1;
    }

    static const struct luaL_Reg functions[] = {
        {"teste", teste},
        {NULL, NULL}
    };

    int luaopen_fstream(lua_State* L){
        luaL_register(L, "fstream", functions);
        return 1;
    }
}