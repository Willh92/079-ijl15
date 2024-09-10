#pragma once

class BossHP
{
public:
	static void Hook();
private:
	static char aBossHpUIToolTip[1304];
	static double dBossHpPercentage;
	//
	static void HookInternal();
	static void HookUpdate();
	static void HookShowMobHPTag();
	static void HookDisposeField();
	static void HookInitField();
	//
	static void SetToolTip_String(int instance, int x, int y, const char* sToolTip);
	static void ClearToolTip(int instance);
	static void DisposeToolTip(int instance);
	static void CreateToolTip(int instance);
	//
	static void DrawBossHpNumberIfNeed();
	static void DrawBossHpNumber(int nHP, int nMaxHP);
	static void DisposeBossHpNumber();
	//
	static int GetMiniMapWidth();

};