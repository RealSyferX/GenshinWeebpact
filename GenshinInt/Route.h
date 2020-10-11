#include "Misc.h"



bool Alt()
{
	Booled[0] = false;
	//true = Directly from address (this wont work if address outdated)
	//false = Scan Using Sig (this wont work if pattern outdated) << i recommend use this

	//Note : Please use Kernel Mode Injection if you dont want get ban (TESTED KERNEL MODE)
	//do not do injection using csrss or else get ban.
	//WriteMemory Kernel = Undetected (TESTED)

	if (!hello)hello = (QWORD)GetModuleHandleA("UserAssembly.dll");
	if (!hello)return 0;


	if (!Booled[0])
	{
		if (!Booled[1])
		{
			NoCD1 = (QWORD)FindPattern(userasem, NOCDHere1, NOCDHere1Ar);
			NoCD2 = (QWORD)FindPattern(userasem, NOCDHere2, NOCDHere2Ar);
			NoCD3 = (QWORD)FindPattern(userasem, NOCDHere3, NOCDHere3Ar);
			Stamina = (QWORD)FindPattern(userasem, Staminaz, StaminazAr) + 0x3;
			BoxTrz = (QWORD)FindPattern(userasem, BoxTreasure1, BoxTreasure1Ar);
			BoxTrz2 = (QWORD)FindPattern(userasem, BoxTreasure2, BoxTreasure2Ar);
			Booled[1] = true;
		}
	}
	else
	{
		if (!Booled[1])
		{
			NoCD1 = (QWORD)(hello + 0x1CBFC34);//0F 10 7B 20 F6 81 0A 01 00 00 01 74 0E 83 B9 BC 00 00 00 00 75 05 E8 01
			NoCD2 = (QWORD)(hello + 0x1CBFD44);//0F 11 43 20 0F 28 74 24 50 48 8B 7C 24 78 0F 28 7C 24 40 48 83 C4 60 5B
			NoCD3 = (QWORD)(hello + 0x1CCE771);//0F 10 70 30 F6 81 0A 01 00 00 01 74 0E 83 B9 BC 00 00 00 00 75 05 E8 C4 AE 9A 02
			BoxTrz = (QWORD)(hello + 0x1C6ED77);//74 1C 48 85 C0 0F 84 CF
			BoxTrz2 = (QWORD)(hello + 0x1C6EDFA);//74 E2 33 D2 48 8B CF
			Booled[1] = true;
		}
	}
}
void Ready()
{
	while (true)
	{
		bool huh = Alt();//Not Clean code there's duplicated bool, but ok
		if (!huh)return;

		/* How set hotkey? (Use this for example)
		* http://www.kbdedit.com/manual/low_level_vk_list.html
		if (GetAsyncKeyState(VK_F1) & 1)
		{
		//Do Stuff in here
		}
		*/
		/* Stamina
		--ON
		OverlordResur((void*)Stamina, "\x90\x90\x90\x90\x90", 5);

		--OFF
		OverlordResur((void*)Stamina, "\xE8\xA7\xA1\x3E\x00", 5);
		*/
		/* No Cooldown 
		--ON
		OverlordResur((void*)NoCD1, "\x90\x90\x90\x90", 4);
		OverlordResur((void*)NoCD2, "\x90\x90\x90\x90", 4);
		OverlordResur((void*)NoCD3, "\x90\x90\x90\x90", 4);

		--OFF
		OverlordResur((void*)NoCD1, "\x0F\x10\x7B\x20", 4);
		OverlordResur((void*)NoCD2, "\x0F\x11\x43\x20", 4);
		OverlordResur((void*)NoCD3, "\x0F\x10\x70\x30", 4);
		*/
		/* Box Treasure Overlay alike esp
		 --ON
		OverlordResur((void*)BoxTrz, "\x75", 1);
		OverlordResur((void*)BoxTrz2, "\x75", 1);

		--OFF
		OverlordResur((void*)BoxTrz, "\x74", 1);
		OverlordResur((void*)BoxTrz2, "\x74", 1);
		*/
		
		Sleep(1000); // well 1second Sleep
	}
}


