#pragma once
#include <string>
#include <fstream>
#include <filesystem>
#include <dirent.h>
namespace fs = std::filesystem;

extern "C" {
    #include <lua/lauxlib.h>
    #include <lua/lualib.h>
    #include <lua/lua.h>

    int fs_writedir(lua_State* L){
        const bool success = fs::create_directory(luaL_checklstring(L, 1, NULL));

        if (success == true) {
            lua_pushboolean(L, 1);
        } else if (success == false) {
            lua_pushnil(L);
        }

        return 1;
    }

    int fs_exists(lua_State* L){
        const bool exists = fs::exists(luaL_checklstring(L, 1, NULL));
        int result;
        if (exists == true) {
            result = 1;
        } else {
            result = 0;
        }

        lua_pushboolean(L, result);

        return 1;
    }

    int fs_readdir(lua_State* L){
        DIR *dir;
        struct dirent *entry;
        int i;
        const char *path = luaL_checkstring(L, 1);

        dir = opendir(path);
        if (dir == NULL) {
            lua_pushnil(L);
            return 1;
        }

        lua_newtable(L);
        i = 1;
        while ((entry = readdir(dir)) != NULL) {
            lua_pushnumber(L, i++);
            lua_pushstring(L, entry->d_name);
            lua_settable(L, -3);
        }

        closedir(dir);
        return 1;
    }
}
