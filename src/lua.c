#include <stdio.h>
#include <emscripten.h>
#include <string.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

void lua(const char *script)
{
    // 初始化 Lua 状态机
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    // 加载 Lua 脚本
    if (luaL_loadstring(L, script))
    {
        const char *errmsg = lua_tostring(L, -1);
        fprintf(stderr, "%s\n", errmsg ? errmsg : "(no error message)");
        lua_pop(L, 1); // 移除错误信息
        fprintf(stderr, "Failed to load Lua script.\n");
        lua_close(L);
        return;
    }

    // 执行 Lua 脚本
    if (lua_pcall(L, 0, LUA_MULTRET, 0))
    {
        const char *errmsg = lua_tostring(L, -1);
        fprintf(stderr, "%s\n", errmsg ? errmsg : "(no error message)");
        lua_pop(L, 1); // 移除错误信息
        fprintf(stderr, "Failed to run Lua script.\n");
    }

    // 清理 Lua 状态机
    lua_close(L);
}

int load_and_run_lua_script(lua_State *L, const char *script)
{
    if (luaL_loadstring(L, script) || lua_pcall(L, 0, LUA_MULTRET, 0))
    {
        // 如果 luaL_loadstring 或 lua_pcall 返回非零值，则表示有错误发生
        fprintf(stderr, "%s\n", lua_tostring(L, -1)); // 输出错误信息
        lua_pop(L, 1);                                // 移除错误信息
        return 1;                                     // 失败
    }
    return 0; // 成功
}