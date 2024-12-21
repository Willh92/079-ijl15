#pragma once
class Resman
{
public:
	static BOOL Hook_InitializeResMan();
	static VOID Hook_InitInlinkOutlink();
	static IWzResMan* getIWzResMan();
};

IWzProperty* getIWzPropertyForPath(std::wstring path);
VARIANTARG* getGetObjectAForPath(std::wstring path);

static void autoFlushCacheTime(int time) {
	Memory::WriteInt(0x004122A8 + 2, time);   //sweep cache delay default 60000
	int SWEEPCACHE_DELAY_2[] = { 0x004122ED, 0x0041243C, 0x0041258E, 0x004126E0, 0x00412813, 0x00412919 };
	for (auto n : SWEEPCACHE_DELAY_2)
	{
		Memory::WriteInt(n + 1, time);  //default 300000
	}
	//flush in CField::Init
	Memory::WriteInt(0x00533F53 + 1, 0);  //default 180000
}

static __declspec(naked) void callFlushcache() {
	__asm {
		push ebx
		push eax
		mov ebx, dword ptr[0x00BE2784]
		mov ebx, [ebx]
		cmp ebx, 00
		jz label_ret
		mov eax, [ebx]
		push 00000000
		push ebx
		call dword ptr[eax + 24H]
		label_ret :
		pop eax
			pop ebx
			ret
	}
}

