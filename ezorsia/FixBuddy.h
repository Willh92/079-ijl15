#pragma once

DWORD fixBuddyAcceptFunc = 0x00A3FA51;
DWORD fixBuddyAcceptJmp = 0x005312D5;
DWORD fixBuddyAcceptRtn = 0x005312A3;
__declspec(naked) void fixBuddyAccept() {
	__asm {
		call fixBuddyAcceptFunc
		cmp byte ptr[ebp - 33h], 9
		jz label_jmp
		jmp fixBuddyAcceptRtn

		label_jmp :
		jmp fixBuddyAcceptJmp
	}
}

class FixBuddy {
public:
	static void Hook() {
		Memory::CodeCave(fixBuddyAccept, 0x0053129E, 5);
	}
};