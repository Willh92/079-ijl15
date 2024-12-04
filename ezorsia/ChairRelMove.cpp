#include "stdafx.h"
#include "ChairRelMove.h"

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
		//case 3012006:
		//	return { 0, 0 };
		//case 3012005:
		//	return { 0, 0 };
		//case 3012001:
		//	return { 0, 0 };
	default:
		return { -INT_MAX, -INT_MAX };
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
	if (pBodyOrigin != nullptr && pChairData.m_nBodyRelMoveX != -INT_MAX)
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
		const wchar_t* nSitAction = L"sit";
		auto pItemInfo = get_item_info(nItemID);

		if (pItemInfo != nullptr)
		{
			auto pBodyRelMove = pItemInfo->get_item<IWzVector2D*>(L"bodyRelMove");
			auto sitAction = pItemInfo->get_item<const wchar_t*>(L"sitAction");

			if (sitAction != nullptr) {
				nSitAction = sitAction;
			}

			if (pBodyRelMove != nullptr)
			{
				nBodyRelMoveX = pBodyRelMove->get_x();
				nBodyRelMoveY = pBodyRelMove->get_y();
				if (!ecx->IsLeft())
				{
					nBodyRelMoveX *= -1;
				}
			}
			else
			{
				auto off = get_chair_rel_move(nItemID);
				nBodyRelMoveX = std::get<0>(off);
				nBodyRelMoveY = std::get<1>(off);
			}
			std::wcout << "hook_CUser__SetActivePortableChair:" << ecx->m_dwCharacterId() << " isLeft : " << (ecx->IsLeft() ? "true" : "false ")
				<< " sitAction:" << nSitAction << " " << nBodyRelMoveX << " " << nBodyRelMoveY << std::endl;
		}

		g_pChairData[ecx->m_dwCharacterId()] = chair_data_t(nBodyRelMoveX, nBodyRelMoveY, nSitAction);

		// looking to the right - adjust view
		if (g_pChairData.find(ecx->m_dwCharacterId()) != g_pChairData.end())
			update_user_body_origin(g_pChairData[ecx->m_dwCharacterId()], ecx->GetAvatar()->m_pBodyOrigin());
	}

	else
	{
		g_pChairData.erase(ecx->m_dwCharacterId());
	}
}

int __fastcall _changeState(CAvatar* ecx, uintptr_t, int state) {
	if (g_pChairData.find(ecx->GetCharacterID()) != g_pChairData.end())
	{
		auto action = g_pChairData[ecx->GetCharacterID()].m_action;
		if (action != L"sit") {
			if(wcsstr(action, L"walk"))
				return ecx->GetUser()->IsLeft() ? 1 : 0;
			else if (wcsstr(action, L"stand"))
				return ecx->GetUser()->IsLeft() ? 5 : 4;
			else if (wcsstr(action, L"prone"))
				return ecx->GetUser()->IsLeft() ? 11 : 10;
		}
		
	}
	return state;
}

chair_data_t* getChair_data_fromId(int userId) {
	if (g_pChairData.find(userId) != g_pChairData.end()) {
		return &g_pChairData[userId];
	}
	return nullptr;
}

const DWORD changeStateJ = 0x00452143;
const DWORD changeStateRet = 0x004520CD;
__declspec(naked) void changeState()
{
	__asm {
		push eax
		call _changeState
		cmp eax, [esi + 0x338]
		je label_j
		jmp changeStateRet
		label_j :
		jmp changeStateJ
	}
}

void Hook_SetActiveChairRelMove(bool bEnable)
{
	Memory::SetHook(bEnable, reinterpret_cast<void**>(&_CUser__SetActivePortableChair), hook_CUser__SetActivePortableChair);
	Memory::SetHook(bEnable, reinterpret_cast<void**>(&_CAvatar__PrepareActionLayer), hook_CAvatar__PrepareActionLayer);
	Memory::SetHook(bEnable, reinterpret_cast<void**>(&_CUser__Update), hook_CUser__Update);
	if (bEnable)
		Memory::CodeCave(changeState, 0x004520C5, 6);
}