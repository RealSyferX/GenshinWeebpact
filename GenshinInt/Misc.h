#include "Byte.h"

#pragma region Definer
static QWORD hello;
static QWORD NoCD1;
static QWORD NoCD2;
static QWORD NoCD3;
static QWORD Stamina;
static QWORD BoxTrz, BoxTrz2;
static bool Booled[50];
#pragma endregion

void OverlordResur(void* BaseAddr, const char* aob, int size)
{
	try {
		DWORD Backup;//Original State
		VirtualProtect((void*)BaseAddr, size, PAGE_EXECUTE_READWRITE, &Backup);
		memcpy((void*)BaseAddr, aob, size);
		VirtualProtect((void*)BaseAddr, size, Backup, NULL);
	}
	catch (...) {}
}
MODULEINFO GetModuleInfo(const wchar_t* szModule)
{
	MODULEINFO modinfo{ 0 };
	HMODULE hModule = GetModuleHandle(szModule);
	if (hModule == 0)
		return modinfo;
	GetModuleInformation(GetCurrentProcess(), hModule, &modinfo, sizeof(MODULEINFO));
	return modinfo;
}
QWORD FindPattern(const wchar_t* module, char* pattern, char* mask)
{
	MODULEINFO mInfo = GetModuleInfo(module);
	QWORD base = (QWORD)mInfo.lpBaseOfDll;//10000000
	QWORD size = (QWORD)mInfo.SizeOfImage;//6000000

	QWORD patternLength = (QWORD)strlen(mask);

	for (QWORD i = 0; i < size - patternLength; i++)
	{
		bool found = true;
		for (QWORD j = 0; j < patternLength; j++)
		{
			found &= mask[j] == '?' || pattern[j] == *(char*)(base + i + j);
		}
		if (found)
		{
			return base + i;
		}
	}

	return NULL;
}