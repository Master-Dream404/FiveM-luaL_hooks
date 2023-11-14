typedef __int64(__fastcall* luaL_loadbufferx)(__int64 L, const char* buff, size_t size, const char* name, const char* mode);

luaL_loadbufferx luaL_loadbuffer = (luaL_loadbufferx)((uintptr_t)GetModuleHandle(L"citizen-scripting-lua.dll") + 0x2B260);

__int64 __fastcall* luaL_loadbuffer_hook(__int64 lua_state, const char* script, size_t script_size, const char* script_name, const char* execute_mode)
{
    if (script_name == "@chat.lua")
    {
        script = "print('hello world')";
        script_size = sizeof(script);
        luaL_loadbuffer(lua_state, script, script_size, script_name, NULL);
    }

    luaL_loadbuffer(lua_state, script, script_size, script_name, execute_mode);
}

typedef __int64(__fastcall* lua_getinfoW)(__int64 a1, const char* a2, __int64 a3);


lua_getinfoW lua_getinfo = (lua_getinfoW)((uintptr_t)GetModuleHandle(L"citizen-scripting-lua.dll") + 0x62690);

__int64* __fastcall to_use(__int64 a1, const char* a2, __int64 a3)
{
    lua_getinfo(a1, ">L", &a3);
}

typedef __int64(__fastcall* lua_nextW)(__int64* a1, int a2);

lua_nextW lua_next = (lua_nextW)((uintptr_t)GetModuleHandle() + 0x2F470);

__int64 lua_state;
lua_next(lua_state, -2);// :D
