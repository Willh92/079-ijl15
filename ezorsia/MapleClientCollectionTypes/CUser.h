#pragma once
class CAvatar;
class CUser
{
public:
	member_at(int, 0x3C0, m_nMoveAction);
	member_at(unsigned int, 0xF2C, m_dwCharacterId);

	CAvatar* GetAvatar();
	bool IsLeft();
};