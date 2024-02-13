// #include <minwindef.h>
// dllmain.cpp : Define o ponto de entrada para o aplicativo DLL.
#include <windows.h>
#include <cstdio>
#include <iostream>

 void DllThread()
{
    Beep(300, 500);
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "W", stdout);
    std::cout << "LEL0 injected" << std::endl;
}

BOOL APIENTRY DllMain(HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved)


{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(0, 0, (LPTHREAD_START_ROUTINE)DllThread, hModule, 0, 0));
        break;
    }
    return TRUE;
}
