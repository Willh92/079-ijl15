#include "stdafx.h"

CUser* CAvatar::GetUser()
{
	return reinterpret_cast<CUser*>(reinterpret_cast<uintptr_t>(this) - 0x88);
}

unsigned int CAvatar::GetCharacterID()
{
	return this->GetUser()->m_dwCharacterId();
}