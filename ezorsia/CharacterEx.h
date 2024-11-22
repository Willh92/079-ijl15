#pragma once
#include <robin_map.h>
class CharacterEx
{
public:
	static int m_loginUserId;
	static tsl::robin_map<int, int> h_userSkin;
	static void InitExpOverride(BOOL bEnable);
	static void InitLevelOverride(BOOL bEnable);
	static void InitDamageSkinOverride(BOOL bEnable);
	static void InitHypontizeFix(BOOL bEnable);
};

