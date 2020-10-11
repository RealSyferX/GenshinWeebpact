#include "Route.h"


BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	//DisableThreadLibraryCalls(hModule);
	if (dwReason == DLL_PROCESS_ATTACH) {
		//MessageBoxA(0, "Insider", "haha", 0);
		CreateThread(0, 0, Ready, 0, 0, 0);// Save thread
	}
	return TRUE;
}

//This code writen by Afdul2021
//It's open source. -(Unknown Cheats)
