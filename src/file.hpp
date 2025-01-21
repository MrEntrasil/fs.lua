#pragma once
#include <string>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

extern "C" {
    #include <lua/lauxlib.h>
    #include <lua/lualib.h>
    #include <lua/lua.h>

    int fs_deletefile(lua_State* L){
        int s = remove(luaL_checklstring(L, 1, NULL));

        if (s == 0)
        {
            lua_pushboolean(L, 1);
        }
        else if (s == -1)
        {
            lua_pushboolean(L, 0);
        }

        return 1;
    }

    int fs_filesize(lua_State* L){
        lua_pushinteger(L, fs::file_size(luaL_checklstring(L, 1, NULL)));
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

        file.close();
        return 1;
    }

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

    int fs_getline(lua_State* L){
        int i;
        std::string c;
        std::fstream file(luaL_checkstring(L, 1));

        if (!file.is_open()) {
            lua_pushnil(L);
            return 1;
        }

        lua_newtable(L);
        i = 1;
        while (std::getline(file, c)) {
            lua_pushnumber(L, i++);
            lua_pushstring(L, c.c_str());
            lua_settable(L, -3);
        }

        return 1;
    }
}
