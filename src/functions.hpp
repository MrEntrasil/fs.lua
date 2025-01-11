#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <dirent.h>

namespace fs = std::filesystem;

extern "C" {
    #include <lua/lua.h>
    #include <lua/lauxlib.h>
    #include <lua/lualib.h>

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

    static const struct luaL_Reg functions[] = {
        {"readfile", fs_readfile},
        {"writefile", fs_writefile},
        {"exists", fs_exists},
        {"readdir", fs_readdir},
        {"getline", fs_getline},
        {NULL, NULL}
    };
}
