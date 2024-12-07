#pragma once
class CUser;

class CAvatar
{
public:
	member_at(int, 0x3BC, m_bForcedInvisible);
	member_at(int, 0x3C0, m_nRidingVehicleID);
	member_at(int, 0x22E8, m_nRidingChairID);
	member_at(int, 0xE1E, m_nChairHeight);
	member_at(wil::com_ptr_t<IWzVector2D>, 0xE34, m_pBodyOrigin);

	CUser* GetUser();
	unsigned int GetCharacterID();
};