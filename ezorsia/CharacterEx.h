#pragma once
#include <map>
class CharacterEx
{
public:
	static int m_loginUserId;
	static std::map<int, int> h_userSkin;
	static void InitExpOverride(BOOL bEnable);
	static void InitLevelOverride(BOOL bEnable);
	static void InitDamageSkinOverride(BOOL bEnable);
};

