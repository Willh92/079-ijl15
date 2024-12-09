#pragma once
#include "MapleClientCollectionTypes/ZXString.h"

typedef ZXString<char>* (__fastcall* _StringPool__GetString_t)(void* pThis, void* edx, ZXString<char>* result, unsigned int nIdx, char formal); //also ty to the creators of MapleClientEditTemplate
static auto _StringPool__GetString = reinterpret_cast<_StringPool__GetString_t>(0x007A4A5E);//hook stringpool modification //ty !! popcorn //ty darter //ty teto

typedef ZXString<wchar_t>* (__fastcall* _StringPool__GetStringW_t)(void* pThis, void* edx, ZXString<wchar_t>* result, unsigned int nIdx, char formal);
static auto _StringPool__GetStringW = reinterpret_cast<_StringPool__GetStringW_t>(0x007A4B2E);//hook stringpool modification //ty !! popcorn //ty darter //ty teto

typedef ZXString<char>* (__fastcall* CItemInfo__GetItemDesc_t)(void* pThis, void* edx, ZXString<char>* result, int nItemID);
static auto CItemInfo__GetItemDesc = reinterpret_cast<CItemInfo__GetItemDesc_t>(0x0060319E);

typedef ZXString<char>* (__fastcall* CItemInfo__GetItemName_t)(void* pThis, void* edx, ZXString<char>* result, int nItemID);
static auto CItemInfo__GetItemName = reinterpret_cast<CItemInfo__GetItemName_t>(0x0060313E);

#pragma region ×øÆïÏà¹Ø
typedef int(__fastcall* Sub_8C9F01_t)(DWORD* pThis, void* edx);
static auto Sub_8C9F01 = reinterpret_cast<Sub_8C9F01_t>(0x008C9F01);

typedef DWORD* (__fastcall* Sub_55A8C1_t)(DWORD* pThis, void* edx);
static auto Sub_55A8C1 = reinterpret_cast<Sub_55A8C1_t>(0x0055A8C1);

typedef BOOL(__fastcall* Sub_8C9F38_t)(DWORD* pThis, void* edx);
static auto Sub_8C9F38 = reinterpret_cast<Sub_8C9F38_t>(0x008C9F38);
#pragma endregion