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
