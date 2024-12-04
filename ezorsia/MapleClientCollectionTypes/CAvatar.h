#pragma once
class CUser;

class CAvatar
{
public:
	member_at(wil::com_ptr_t<IWzVector2D>, 0xE34, m_pBodyOrigin);

	CUser* GetUser();
	unsigned int GetCharacterID();
};