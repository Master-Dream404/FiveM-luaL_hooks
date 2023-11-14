//#define luaL_loadbuffer(L,s,sz,n)	luaL_loadbufferx(L,s,sz,n,NULL)
//__int64 __fastcall sub_2B260(__int64 a1, __int64 a2, __int64 a3, const char *a4, __int64 a5)

typedef __int64(__fastcall* Lua_CreateThreadNowW)(__int64 lua_state);

Lua_CreateThreadNowW Lua_CreateThreadNow = (Lua_CreateThreadNowW)((uintptr_t)GetModuleHandle(L"citizen-scripting-lua.dll") + 0x16A50);
//__int64 __fastcall sub_18DB0(__int64 a1)
typedef __int64(__fastcall* Lua_CreateHostFileThreadW)(__int64 L);

Lua_CreateHostFileThreadW Lua_CreateHostFileThread = (Lua_CreateHostFileThreadW)((uintptr_t)GetModuleHandle(L"citizen-scripting-lua.dll") + 0x18DB0);

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

typedef __int64(__fastcall* lua_nextW)(__int64* a1, int a2);

lua_nextW lua_next = (lua_nextW)((uintptr_t)GetModuleHandle(L"citizen-scripting-lua.dll") + 0x2F470);

__int64 lua_state;
lua_next(lua_state, -2);// :D
