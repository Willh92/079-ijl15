#pragma once
#include <tuple>
#include <robin_map.h>
#include "include/wil/com.h"

#define member_at(T, offset, name) auto& name() { return *reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(this) + offset); }

DECLARE_INTERFACE_IID_(IWzVector2D, IUnknown, "F28BD1ED-3DEB-4F92-9EEC-10EF5A1C3FB4")
{
	BEGIN_INTERFACE;

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppv) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;
	STDMETHOD(get_persistentUOL)(THIS_ wchar_t**) PURE;
	STDMETHOD(raw_Serialize)(THIS_ uintptr_t*) PURE;
	STDMETHOD(get_item)(THIS_ tagVARIANT, tagVARIANT*) PURE;
	STDMETHOD(get__NewEnum)(THIS_ IUnknown**) PURE;
	STDMETHOD(get_count)(THIS_ unsigned int*) PURE;
	STDMETHOD(get_x)(THIS_ int*) PURE;
	STDMETHOD(put_x)(THIS_ int) PURE;
	STDMETHOD(get_y)(THIS_ int*) PURE;
	STDMETHOD(put_y)(THIS_ int) PURE;
	STDMETHOD(get_x2)(THIS_ int*) PURE;
	STDMETHOD(put_x2)(THIS_ int) PURE;
	STDMETHOD(get_y2)(THIS_ int*) PURE;
	STDMETHOD(put_y2)(THIS_ int) PURE;
	STDMETHOD(raw_Move)(THIS_ int, int) PURE;
	STDMETHOD(raw_Offset)(THIS_ int, int) PURE;
	STDMETHOD(raw_Scale)(THIS_ int, int, int, int, int, int) PURE;
	STDMETHOD(raw_Insert)(THIS_ tagVARIANT, tagVARIANT) PURE;
	STDMETHOD(raw_Remove)(THIS_ tagVARIANT, tagVARIANT*) PURE;
	STDMETHOD(raw_Init)(THIS_ int, int) PURE;
	STDMETHOD(get_currentTime)(THIS_ int*) PURE;
	STDMETHOD(put_currentTime)(THIS_ int) PURE;
	STDMETHOD(get_origin)(THIS_ tagVARIANT*) PURE;
	STDMETHOD(put_origin)(THIS_ tagVARIANT) PURE;
	STDMETHOD(get_rx)(THIS_ int*) PURE;
	STDMETHOD(put_rx)(THIS_ int) PURE;
	STDMETHOD(get_ry)(THIS_ int*) PURE;
	STDMETHOD(put_ry)(THIS_ int) PURE;
	STDMETHOD(get_a)(THIS_ long double*) PURE;
	STDMETHOD(get_ra)(THIS_ long double*) PURE;
	STDMETHOD(put_ra)(THIS_ long double) PURE;
	STDMETHOD(get_flipX)(THIS_ int*) PURE;
	STDMETHOD(put_flipX)(THIS_ int) PURE;
	STDMETHOD(raw__GetSnapshot)(THIS_ int*, int*, int*, int*, int*, int*, long double*, long double*, tagVARIANT) PURE;
	STDMETHOD(raw_RelMove)(THIS_ int nX, int nY, _variant_t nTime, _variant_t nType) PURE;
	STDMETHOD(raw_RelOffset)(THIS_ int, int, tagVARIANT, tagVARIANT) PURE;
	STDMETHOD(raw_Ratio)(THIS_ IWzVector2D*, int, int, int, int) PURE;
	STDMETHOD(raw_WrapClip)(THIS_ tagVARIANT, int, int, unsigned int, unsigned int, tagVARIANT) PURE;
	STDMETHOD(raw_Rotate)(THIS_ long double, tagVARIANT) PURE;
	STDMETHOD(get_looseLevel)(THIS_ unsigned int*) PURE;
	STDMETHOD(put_looseLevel)(THIS_ unsigned int) PURE;
	STDMETHOD(raw_Fly)(THIS_ tagVARIANT*, int) PURE;

	int get_x()//
	{
		int x;
		this->get_x(&x);

		return x;
	}

	int get_y()
	{
		int y;
		this->get_y(&y);

		return y;
	}

	END_INTERFACE;
};

DECLARE_INTERFACE_IID_(IWzProperty, IUnknown, "986515D9-0A0B-4929-8B4F-718682177B92")
{
	BEGIN_INTERFACE;

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppv) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	/*** IWzSerialize methods ***/
	STDMETHOD(get_persistentUOL)(THIS_ wchar_t**) PURE;
	STDMETHOD(raw_Serialize)(THIS_ uintptr_t*) PURE;

	/*** IWzProperty methods ***/
	STDMETHOD(get_item)(THIS_ const wchar_t* wsPath, _variant_t * result);
	STDMETHOD(put_item)(THIS_ const wchar_t* wsPath, _variant_t pItem);
	STDMETHOD(get__NewEnum)(THIS_ IUnknown**);
	STDMETHOD(get_count)(THIS_ unsigned int*);
	STDMETHOD(raw_Add)(THIS_ wchar_t*, tagVARIANT, tagVARIANT);
	STDMETHOD(raw_Remove)(THIS_ wchar_t*);
	STDMETHOD(raw_Import)(THIS_ wchar_t*);
	STDMETHOD(raw__GetHeadPosition)(THIS_ unsigned int**);
	STDMETHOD(raw__GetAt)(THIS_ unsigned int*, tagVARIANT*);
	STDMETHOD(raw__GetName)(THIS_ unsigned int*, wchar_t**);
	STDMETHOD(raw__GetNext)(THIS_ unsigned int**);

	template <typename T>
	T get_item(const wchar_t* wsPath)
	{
		_variant_t pItem(0);
		this->get_item(wsPath, &pItem);

		return reinterpret_cast<T>(pItem.ppunkVal);
	}

	END_INTERFACE;
};

class CAvatar;

class CUser
{
public:
	member_at(int, 0x3C0, m_nMoveAction);
	member_at(unsigned int, 0xF2C, m_dwCharacterId);

	CAvatar* GetAvatar();
	bool IsLeft();
};

class CUser;

class CAvatar
{
public:
	member_at(wil::com_ptr_t<IWzVector2D>, 0xE34, m_pBodyOrigin);

	CUser* GetUser();
	unsigned int GetCharacterID();
};


CUser* CAvatar::GetUser()
{
	return reinterpret_cast<CUser*>(reinterpret_cast<uintptr_t>(this) - 0x88);
}

unsigned int CAvatar::GetCharacterID()
{
	return this->GetUser()->m_dwCharacterId();
}


CAvatar* CUser::GetAvatar()
{
	return reinterpret_cast<CAvatar*>(reinterpret_cast<uintptr_t>(this) + 0x88);
}

bool CUser::IsLeft()
{
	return (this->m_nMoveAction() & 1) > 0;
}

struct chair_data_t
{
	chair_data_t() {}
	chair_data_t(int nBodyRelMoveX, int nBodyRelMoveY) : m_nBodyRelMoveX(nBodyRelMoveX), m_nBodyRelMoveY(nBodyRelMoveY) {}

	int m_nBodyRelMoveX = 0;
	int m_nBodyRelMoveY = 0;
	bool m_bFirstCall = true;
};

tsl::robin_map<unsigned int, chair_data_t> g_pChairData;

uintptr_t g_pCItemInfo = 0x00BD8FE8;
typedef IWzProperty* (__thiscall* CItemInfo__GetItemInfo_t)(uintptr_t ecx, IWzProperty** result, const int nItemID);
auto _CItemInfo__GetItemInfo = reinterpret_cast<CItemInfo__GetItemInfo_t>(0x0060F2EF);

typedef void(__thiscall* CUserLocal__Update_t)(uintptr_t ecx);
auto _CUserLocal__Update = reinterpret_cast<CUserLocal__Update_t>(0x00951470);

typedef void(__thiscall* CUser__SetActivePortableChair_t)(CUser* ecx, int nItemID);
auto _CUser__SetActivePortableChair = reinterpret_cast<CUser__SetActivePortableChair_t>(0x00943070);

typedef void(__thiscall* CUser__Update_t)(CUser* ecx);
auto _CUser__Update = reinterpret_cast<CUser__Update_t>(0x009371D9);

typedef void(__thiscall* CAvatar__PrepareActionLayer_t)(CAvatar* ecx, int nActionSpeed, int nWalkSpeed, int bKeyDown);
auto _CAvatar__PrepareActionLayer = reinterpret_cast<CAvatar__PrepareActionLayer_t>(0x00453A5A);

static std::tuple<int, int> get_chair_rel_move(int itemId) {
	switch (itemId) {
	case 3012006:
		return { 0, 0 };
	case 3012005:
		return { 0, 0 };
	case 3012001:
		return { 0, 0 };
	default:
		return { 0, 0 };
	}
}

IWzProperty* get_item_info(const int nItemID)
{
	IWzProperty* pResult;
	_CItemInfo__GetItemInfo(g_pCItemInfo, &pResult, nItemID);

	return pResult;
}



void update_user_body_origin(const chair_data_t& pChairData, wil::com_ptr_t<IWzVector2D> pBodyOrigin)
{
	if (pBodyOrigin != nullptr)
	{
		//std::cout << "update_user_body_origin:" << pBodyOrigin->get_x() << " " << pBodyOrigin->get_y() << std::endl;

		pBodyOrigin->raw_RelMove(pChairData.m_nBodyRelMoveX, pChairData.m_nBodyRelMoveY, 0, 0);
	}
}



void __fastcall hook_CUser__Update(CUser* ecx, uintptr_t)
{
	_CUser__Update(ecx);

	static DWORD lastUpdate = 0;
	auto t = GetTickCount();
	//if(t - lastUpdate > 5000) {
	//	DiscordRichPresence::getInstance().updatePresence(GetJobCode(), GetCharacterLevel(), GetCharacterName());
	//	lastUpdate = t;
	//}

	if (g_pChairData.find(ecx->m_dwCharacterId()) != g_pChairData.end())
	{
		auto& pChairData = g_pChairData[ecx->m_dwCharacterId()];

		// prevents the chair from going above
		if (!pChairData.m_bFirstCall)
		{
			update_user_body_origin(pChairData, ecx->GetAvatar()->m_pBodyOrigin());
		}

		pChairData.m_bFirstCall = false;
	}
}

void __fastcall hook_CAvatar__PrepareActionLayer(CAvatar* ecx, uintptr_t, int nActionSpeed, int nWalkSpeed, int bKeyDown)
{
	_CAvatar__PrepareActionLayer(ecx, nActionSpeed, nWalkSpeed, bKeyDown);

	if (g_pChairData.find(ecx->GetCharacterID()) != g_pChairData.end())
	{
		auto& pChairData = g_pChairData[ecx->GetCharacterID()];

		if (!pChairData.m_bFirstCall)
		{
			update_user_body_origin(g_pChairData[ecx->GetCharacterID()], ecx->m_pBodyOrigin());
		}

		pChairData.m_bFirstCall = false;
	}
}

void __fastcall hook_CUser__SetActivePortableChair(CUser* ecx, uintptr_t, int nItemID)
{
	_CUser__SetActivePortableChair(ecx, nItemID);

	if (nItemID != 0)
	{
		int nBodyRelMoveX = 0;
		int nBodyRelMoveY = 0;
		auto pItemInfo = get_item_info(nItemID);

		if (pItemInfo != nullptr)
		{
			auto pBodyRelMove = pItemInfo->get_item<IWzVector2D*>(L"bodyRelMove");

			if (pBodyRelMove != nullptr)
			{
				nBodyRelMoveX = pBodyRelMove->get_x();
				nBodyRelMoveY = pBodyRelMove->get_y();
				if (!ecx->IsLeft())
				{
					nBodyRelMoveX *= -1;
				}
				//std::cout << "hook_CUser__SetActivePortableChair:" << ecx->m_dwCharacterId() << " isLeft : " << (ecx->IsLeft() ? "true" : "false ")
				//	<< nBodyRelMoveX << " " << nBodyRelMoveY << std::endl;

				g_pChairData[ecx->m_dwCharacterId()] = chair_data_t(nBodyRelMoveX, nBodyRelMoveY);
			}
			/*else
			{
				auto off = get_chair_rel_move(nItemID);
				nBodyRelMoveX = std::get<0>(off);
				nBodyRelMoveY = std::get<1>(off);
			}*/
		}


		// looking to the right - adjust view
		if (g_pChairData.find(ecx->m_dwCharacterId()) != g_pChairData.end())
			update_user_body_origin(g_pChairData[ecx->m_dwCharacterId()], ecx->GetAvatar()->m_pBodyOrigin());
	}

	else
	{
		g_pChairData.erase(ecx->m_dwCharacterId());
	}
}

void Hook_SetActiveChairRelMove(bool bEnable)
{
	Memory::SetHook(true, reinterpret_cast<void**>(&_CUser__SetActivePortableChair), hook_CUser__SetActivePortableChair);
	Memory::SetHook(true, reinterpret_cast<void**>(&_CAvatar__PrepareActionLayer), hook_CAvatar__PrepareActionLayer);
	Memory::SetHook(true, reinterpret_cast<void**>(&_CUser__Update), hook_CUser__Update);
}