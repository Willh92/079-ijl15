#pragma once
#ifndef CHAIR_REL_MOVE_H
#define CHAIR_REL_MOVE_H

struct chair_data_t
{
	chair_data_t() {}
	chair_data_t(int nBodyRelMoveX, int nBodyRelMoveY) : m_nBodyRelMoveX(nBodyRelMoveX), m_nBodyRelMoveY(nBodyRelMoveY) {}
	chair_data_t(int nBodyRelMoveX, int nBodyRelMoveY, const wchar_t* nAction) : m_nBodyRelMoveX(nBodyRelMoveX), m_nBodyRelMoveY(nBodyRelMoveY), m_action(nAction) {}

	int m_nBodyRelMoveX = 0;
	int m_nBodyRelMoveY = 0;
	bool m_bFirstCall = true;
	const wchar_t* m_action = L"sit";
};

IWzProperty* get_item_info(const int nItemID);

chair_data_t* getChair_data_fromId(int userId);

void Hook_SetActiveChairRelMove(bool bEnable);

#endif