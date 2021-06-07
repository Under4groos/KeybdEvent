

#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <io.h>

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


BYTE scan_code(DWORD pKey)
{
    const DWORD result = MapVirtualKey(pKey, MAPVK_VK_TO_VSC);
    return static_cast<BYTE>(result);
}
void press_key(DWORD pKey)
{
    keybd_event(static_cast<BYTE>(pKey), scan_code(pKey), 0, 0);
}
void  release_key(DWORD pKey)
{
    keybd_event(static_cast<BYTE>(pKey), scan_code(pKey), KEYEVENTF_KEYUP, 0);
}
#define PRESS(x) press_key(x); 
#define RELEASE(x) release_key(x);


extern "C"
{
    __declspec(dllexport) void SendKeyInt(int key)
    {
        PRESS(key);
        RELEASE(key);
    }
    __declspec(dllexport) void KeyPress(int key)
    {
        PRESS(key);
    }
    __declspec(dllexport) void KeyRelese(int key)
    {
        RELEASE(key);
    }

}