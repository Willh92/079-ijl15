#include "stdafx.h"

CAvatar* CUser::GetAvatar()
{
	return reinterpret_cast<CAvatar*>(reinterpret_cast<uintptr_t>(this) + 0x88);
}

bool CUser::IsLeft()
{
	return (this->m_nMoveAction() & 1) > 0;
}