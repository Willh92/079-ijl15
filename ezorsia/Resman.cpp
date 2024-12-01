#include "stdafx.h"
#include "Resman.h"
#include <sys/stat.h>
#include <algorithm>
#include "IWzProperty.h"
#include <sstream>
#include <CharacterEx.h>

VARIANTARG errorVar = { VT_ERROR, 0, 0, 0x80020004 };
IWzProperty* damageSkinImg;

enum RESMAN_PARAM {
	RC_AUTO_SERIALIZE = 0x1,
	RC_AUTO_SERIALIZE_NO_CACHE = 0x2,
	RC_NO_AUTO_SERIALIZE = 0x4,
	RC_DEFAULT_AUTO_SERIALIZE = 0x0,
	RC_AUTO_SERIALIZE_MASK = 0x7,
	RC_AUTO_REPARSE = 0x10,
	RC_NO_AUTO_REPARSE = 0x20,
	RC_DEFAULT_AUTO_REPARSE = 0x0,
	RC_AUTO_REPARSE_MASK = 0x30,
};

typedef void(__fastcall* CWvsApp__InitializeResMan_t)(void*);
typedef DWORD(__fastcall* _Ztl_variant_t__GetUnknown)(VARIANTARG* This, void* notuse, bool a2, bool a3);
typedef VARIANTARG* (__fastcall* _IWzResMan__GetObjectA)(DWORD* This, void* notuse, VARIANTARG* pvargDest, int* sUOL, int vParam, int vAux);
typedef VARIANTARG* (__fastcall* _IWzProperty__GetItem)(IUnknown* This, void* notuse, VARIANTARG* pvargDest, int* sPath);
typedef IUnknown* (__fastcall* _IWzUOL_QueryInterface)(DWORD* This, void* notuse, IUnknown* a2);
typedef int(__fastcall* _IWzUOL__GetfilePath)(DWORD* This, void* notuse, int a2);
typedef int(__fastcall* _IWzCanvas_operator_equal)(DWORD* This, void* notuse, DWORD* a2);
typedef int(__fastcall* _IWzCanvas__Getwidth)(DWORD* This, void* notuse);
typedef int(__fastcall* _IWzCanvas__Getheight)(DWORD* This, void* notuse);
typedef DWORD(__fastcall* _IWzCanvas__GetProperty)(DWORD* This, void* notuse, IUnknown** a2);
typedef DWORD* (__cdecl* _get_unknown)(DWORD*, VARIANT*);
typedef int(__fastcall* _bstr_constructor_wchar)(void* ecx, void* edx, const wchar_t* str);

// Function Address
auto CWvsApp__InitializeResMan = reinterpret_cast<CWvsApp__InitializeResMan_t>(0x009FFF26);

auto PcCreateObject_IWzResMan = (void(__cdecl*)(const wchar_t*, void*, void*))0x00A04307;
auto PcCreateObject_IWzNameSpace = (void(__cdecl*)(const wchar_t*, void*, void*))0x00A0436C;
auto PcCreateObject_IWzFileSystem = (void(__cdecl*)(const wchar_t*, void*, void*))0x00A043D1;
auto CWvsApp__Dir_BackSlashToSlash = (void(__cdecl*)(void*))0x00A01E28;
auto CWvsApp__Dir_upDir = (void(__cdecl*)(void*))0x00A01EAA;
auto bstr_constructor = (void(__fastcall*)(void*, void*, const char*))0x004063D7;
auto IWzFileSystem__Init = (void* (__fastcall*)(void*, void*, void*))0x00A00D93;
auto IWZNameSpace__Mount = (void* (__fastcall*)(void*, void*, void*, void*, void*))0x00A00D39;

_Ztl_variant_t__GetUnknown Ztl_variant_t__GetUnknown = (_Ztl_variant_t__GetUnknown)0x004032B2;
_IWzResMan__GetObjectA IWzResMan__GetObjectA = (_IWzResMan__GetObjectA)0x00404A75;
_IWzProperty__GetItem IWzProperty__GetItem = (_IWzProperty__GetItem)0x00403AC7;
_IWzUOL_QueryInterface IWzUOL_QueryInterface = (_IWzUOL_QueryInterface)0x004170BD;
_IWzUOL__GetfilePath IWzUOL__GetfilePath = (_IWzUOL__GetfilePath)0x004152B1;
_IWzCanvas_operator_equal IWzCanvas_operator_equal = (_IWzCanvas_operator_equal)0x0041EF46;
_IWzCanvas__Getwidth IWzCanvas__Getwidth = (_IWzCanvas__Getwidth)0x0040C250;
_IWzCanvas__Getheight IWzCanvas__Getheight = (_IWzCanvas__Getheight)0x0040C2E7;
_IWzCanvas__GetProperty IWzCanvas__GetProperty = (_IWzCanvas__GetProperty)0x00404BA3;
_get_unknown get_unknown = (_get_unknown)0x0041511B;
_bstr_constructor_wchar bstr_constructor_wchar = (_bstr_constructor_wchar)0x00402C82;

// DWORD Address
auto g_rm = (void**)0x00BE2784;
auto g_root = (void**)0x00BE277C;
auto pNameSpace = 0x00BE1FC0;

DWORD* GetResManInstance()
{
	return (DWORD*)*g_rm;
}

struct WZPath
{
	IUnknown* parent;
	std::wstring rootPath;
	std::wstring name;
};

tsl::robin_map<IUnknown*, std::shared_ptr<WZPath>> imgPath;
void* GetUOLProperty(VARIANT* prop, void** result)
{
	if (prop == NULL || result == NULL)
		return NULL;
	IUnknown* pUnk = (IUnknown*)Ztl_variant_t__GetUnknown(prop, nullptr, 0, 0);
	if (pUnk)
	{
		pUnk->AddRef();
		IUnknown* pWzUOL = NULL;
		IWzUOL_QueryInterface((DWORD*)&pWzUOL, nullptr, (IUnknown*)&pUnk);

		if (pWzUOL)
		{
			IWzUOL__GetfilePath((DWORD*)pWzUOL, nullptr, (int)result);
			if (*result) {
				return *result;
			}
		}
	}
	return NULL;
}

std::wstring GetImgFullPath(std::wstring strT)
{
	std::wstring lstr = strT;
	std::transform(lstr.begin(), lstr.end(), lstr.begin(), towlower);

	int pos = lstr.rfind(L".img");
	if (pos != std::string::npos)
	{
		pos += 4; // 4
		strT = strT.substr(0, pos);
		strT += L"/";
	}
	return strT;
}

VARIANTARG* __fastcall IWzResMan__GetObjectA_Hook(DWORD* This, void* notuse, VARIANTARG* pvargDest, int* sUOL, int vParam, int vAux)
{
	std::wstring strT = (wchar_t*)*sUOL;

	auto ret = IWzResMan__GetObjectA(This, nullptr, pvargDest, sUOL, vParam, vAux);
	//if (strT.find(L"2503") != std::wstring::npos) {
	//	std::wcout << "IWzResMan__GetObjectA_Hook :" << ret->punkVal << " " << strT << std::endl;
	//}
	if (ret && ret->vt == VT_UNKNOWN)
	{
		WZPath wz;
		wz.parent = nullptr;
		wz.rootPath = strT;
		wz.name = strT;
		imgPath[ret->punkVal] = std::make_shared<WZPath>(wz);
	}
	return ret;
};

VARIANTARG* __fastcall IWzProperty__GetItem_Hook(IWzProperty* This, void* notuse, VARIANTARG* pvargDest, int* sPath)
{
	std::wstring strT = (wchar_t*)*sPath;

	auto ret = IWzProperty__GetItem(This, nullptr, pvargDest, sPath);
	if (Client::tamingMob198Effect) {
		if (pvargDest->vt == VT_EMPTY && strT.find(L"stand1") != std::wstring::npos) {
			if (imgPath.find(This) != imgPath.end() && imgPath[This]->name.find(L"TamingMob/0198"))
			{
				try {
					std::wostringstream oss;
					oss << GetImgFullPath(imgPath[This]->rootPath.c_str());
					oss << "sit";
					std::wstring path = oss.str();
					//ret = IWzProperty__GetItem(This, nullptr, pvargDest, (int*)&path);  读取不到sit节点
					VARIANTARG pvarg1 = errorVar;
					VARIANTARG pvarg2 = errorVar;
					ret = IWzResMan__GetObjectA(GetResManInstance(), nullptr, pvargDest, (int*)&path, (int)&pvarg1, (int)&pvarg2);
					//std::wcout << "IWzProperty__GetItem_Hook :" << This << " " << strT << "->" << path << " " << pvargDest->vt << imgPath[This]->name << std::endl;
				}
				catch (...) {
				}
			}
		}
	}
	if (pvargDest->vt == VT_UNKNOWN)
	{
		if (imgPath.find(This) != imgPath.end())
		{
			WZPath wz;
			wz.name = strT;
			wz.rootPath = imgPath[This]->rootPath;
			wz.parent = This;
			imgPath[pvargDest->punkVal] = std::make_shared<WZPath>(wz);
		}
	}
	//void* sUOL = NULL;
	//GetUOLProperty(pvargDest, &sUOL);
	//if (sUOL)
	//{
	//	VARIANTARG pvarg1 = errorVar;
	//	VARIANTARG pvarg2 = errorVar;
	//	ret = IWzResMan__GetObjectA(GetResManInstance(), nullptr, pvargDest, (int*)sUOL, (int)&pvarg1, (int)&pvarg2);
	//}
	return ret;
};


int attackObject = 0;
const DWORD attackObjectAddr = 0x0019DD94 + 8;
__declspec(naked) void getattackObjectId() {

	__asm {
		push eax
		mov eax, [attackObjectAddr]
		mov eax, dword ptr[eax]
		mov attackObject, eax
		pop eax
		ret
	}
}


VARIANTARG* __fastcall IWzProperty__GetSkinItem_Hook(IWzProperty* This, void* notuse, VARIANTARG* pvargDest, int* sPath)
{
	std::wstring strT = (wchar_t*)*sPath;

	if ((Client::DamageSkin > 0 || Client::RemoteDamageSkin) && damageSkinImg) {
		try {
			getattackObjectId();
			int skinId = (Client::DamageSkin > 0 && attackObject == CharacterEx::m_loginUserId) ? Client::DamageSkin : 0;
			if (Client::RemoteDamageSkin) {
				auto it = CharacterEx::h_userSkin.find(attackObject);
				if (it != CharacterEx::h_userSkin.end()) {
					skinId = it->second;
				}
			}
			std::wstring name;
			if (imgPath.find(This) != imgPath.end())
			{
				name = (*imgPath[This]).name;
			}
			//std::wcout << This << " " << attackObject << " " << skinId << std::endl;
			if (skinId != 0) {
				if (name == L"NoRed0" || name == L"NoRed1" || name == L"NoCri0" || name == L"NoCri1") {
					std::wostringstream oss;
					oss << skinId;
					oss << "/";
					oss << name;
					oss << "/";
					oss << strT;
					std::wstring path = oss.str();
					auto ret = IWzProperty__GetItem(damageSkinImg, nullptr, pvargDest, (int*)&path);
					if (ret && ret->vt == VT_UNKNOWN)
					{
						return ret;
					}
				}
			}
		}
		catch (...) {}
	}
	return  IWzProperty__GetItem(This, nullptr, pvargDest, sPath);
};

DWORD GetCanvasPropertyByPath(DWORD* This, std::wstring path, DWORD* result)
{
	VARIANT varDest = { 0 };
	VARIANT var1 = { 0 };
	VARIANT var2 = { 0 };
	DWORD varUnk = 0;
	void* sUol = NULL;
	bstr_constructor_wchar(&sUol, nullptr, path.c_str());
	auto v9 = IWzResMan__GetObjectA((DWORD*)*g_rm, nullptr, &varDest, (int*)sUol, (int)&var1, (int)&var2);
	auto v10 = get_unknown(&varUnk, v9);
	return IWzCanvas_operator_equal(result, nullptr, v10);
}

int __fastcall IWzCanvas_operator_equal_Hook(DWORD* This, void* notuse, DWORD* a2)
{
	auto ret = IWzCanvas_operator_equal(This, nullptr, a2);
	IUnknown* prop = NULL;
	void* pStrInlink = NULL;
	void* pStrOutlink = NULL;
	VARIANT dst = { 0 };
	int w = 0, h = 0;
	if (!*This)
		goto RET;

	w = IWzCanvas__Getwidth((DWORD*)*This, nullptr);
	h = IWzCanvas__Getheight((DWORD*)*This, nullptr);

	if (w > 1 || h > 1)
		goto RET;

	IWzCanvas__GetProperty((DWORD*)*This, nullptr, &prop);

	if (!prop)
		goto RET;

	bstr_constructor(&pStrInlink, nullptr, "_inlink");

	if (!pStrInlink)
		goto OUTLINK;

	IWzProperty__GetItem(prop, nullptr, &dst, (int*)pStrInlink);

	if (!dst.vt) {
		goto OUTLINK;
	}

	if (dst.vt == VT_BSTR)
	{
		void* link = NULL;
		if (dst.bstrVal)
		{
			IUnknown* pUnk = (IUnknown*)*a2;
			DWORD ptr = 0;

			if (imgPath.find(pUnk) != imgPath.end())
			{
				ret = GetCanvasPropertyByPath(This, GetImgFullPath(imgPath[pUnk]->rootPath.c_str()) + dst.bstrVal, (DWORD*)&ptr);
				if (ptr) {
					*This = ptr;
				}
			}
		}
	}

OUTLINK:
	bstr_constructor(&pStrOutlink, nullptr, "_outlink");
	IWzProperty__GetItem(prop, nullptr, &dst, (int*)pStrOutlink);

	if (!dst.vt)
		goto RET;

	if (dst.vt == VT_BSTR)
	{
		void* link = NULL;
		if (dst.bstrVal)
		{
			DWORD ptr = 0;
			ret = GetCanvasPropertyByPath(GetResManInstance(), dst.bstrVal, (DWORD*)&ptr);
			if (ptr)
				*This = ptr;
		}
	}


RET:
	if (prop)
		((IUnknown*)prop)->Release();
	return ret;
};

// Disable Restrictions
#pragma optimize("", off)

VOID loadDamageFile() {
	VARIANTARG pvargDest = {};
	VARIANTARG pvarg1 = errorVar;
	VARIANTARG pvarg2 = errorVar;
	std::wstring path = L"Effect/DamageSkin.img/";
	try {
		auto ret = IWzResMan__GetObjectA(GetResManInstance(), nullptr, &pvargDest, (int*)&path, (int)&pvarg1, (int)&pvarg2);
		if (ret && ret->vt == VT_UNKNOWN)
		{
			damageSkinImg = (IWzProperty*)Ztl_variant_t__GetUnknown(ret, nullptr, 0, 0);
		}
	}
	catch (...) {}
}

BOOL Resman::Hook_InitializeResMan() {
	autoFlushCacheTime(10000);

	CWvsApp__InitializeResMan_t Hook = [](void*) {

		struct stat sb;

		if (stat("./Base.wz", &sb) == 0) {
			CWvsApp__InitializeResMan(nullptr);
		}
		else {
			// Generic
			void* pData = nullptr;
			void* pFileSystem = nullptr;
			void* pUnkOuter = 0;
			void* nPriority = 0;
			void* sPath;

			// Resman
			PcCreateObject_IWzResMan(L"ResMan", g_rm, pUnkOuter);

			void* pIWzResMan_Instance = *g_rm;
			//auto IWzResMan__SetResManParam = *(void(__cdecl**)(void*, int, int, int))((*(int*)pIWzResMan_Instance) + 20); // Hard Coded
			//IWzResMan__SetResManParam(pIWzResMan_Instance, RC_AUTO_REPARSE | RC_AUTO_SERIALIZE, -1, -1);
			auto IWzResMan__SetResManParam = *(void(__fastcall**)(void*, void*, void*, int, int, int))((*(int*)pIWzResMan_Instance) + 20);
			IWzResMan__SetResManParam(nullptr, nullptr, pIWzResMan_Instance, RC_AUTO_REPARSE | RC_AUTO_SERIALIZE, 60000, -1);  //180000 - > 60000 ?

			// NameSpace
			PcCreateObject_IWzNameSpace(L"NameSpace", g_root, pUnkOuter);

			void* pIWzNameSpace_Instance = g_root;
			auto PcSetRootNameSpace = (void(__cdecl*)(void*, int)) * (int*)pNameSpace; // Hard Coded
			PcSetRootNameSpace(pIWzNameSpace_Instance, 1);

			// Game FileSystem
			PcCreateObject_IWzFileSystem(L"NameSpace#FileSystem", &pFileSystem, pUnkOuter);

			char sStartPath[MAX_PATH];
			GetModuleFileNameA(NULL, sStartPath, MAX_PATH);
			CWvsApp__Dir_BackSlashToSlash(sStartPath);
			CWvsApp__Dir_upDir(sStartPath);

			bstr_constructor(&sPath, pData, sStartPath);

			auto iGameFS = IWzFileSystem__Init(pFileSystem, pData, sPath);

			bstr_constructor(&sPath, pData, "/");

			auto mGameFS = IWZNameSpace__Mount(*g_root, pData, sPath, pFileSystem, nPriority);

			// Data FileSystem
			PcCreateObject_IWzFileSystem(L"NameSpace#FileSystem", &pFileSystem, pUnkOuter);

			if (stat("./Data", &sb) == 0) {
				bstr_constructor(&sPath, pData, "./Data");
			}
			else if (stat("../Data", &sb) == 0) {
				bstr_constructor(&sPath, pData, "../Data");
			}
			else {
				bstr_constructor(&sPath, pData, "/");
			}

			auto iDataFS = IWzFileSystem__Init(pFileSystem, pData, sPath);

			bstr_constructor(&sPath, pData, "/");

			auto mDataFS = IWZNameSpace__Mount(*g_root, pData, sPath, pFileSystem, nPriority);
		}
		//加载皮肤文件
		loadDamageFile();

		};

	return Memory::SetHook(true, reinterpret_cast<void**>(&CWvsApp__InitializeResMan), Hook);
}

VOID Resman::Hook_InitInlinkOutlink() {
	Memory::SetHook(true, reinterpret_cast<void**>(&IWzProperty__GetItem), IWzProperty__GetItem_Hook);
	Memory::SetHook(true, reinterpret_cast<void**>(&IWzResMan__GetObjectA), IWzResMan__GetObjectA_Hook);
	Memory::SetHook(true, reinterpret_cast<void**>(&IWzCanvas_operator_equal), IWzCanvas_operator_equal_Hook);
	//skin
	if (Client::DamageSkin > 0 || Client::RemoteDamageSkin) {
		Memory::PatchCall(0x0043873E, IWzProperty__GetSkinItem_Hook);
		Memory::PatchCall(0x00437BDA, IWzProperty__GetSkinItem_Hook);
		Memory::PatchCall(0x00437B62, IWzProperty__GetSkinItem_Hook);
		Memory::PatchCall(0x00437F8E, IWzProperty__GetSkinItem_Hook);
		Memory::PatchCall(0x00437DFE, IWzProperty__GetSkinItem_Hook);
	}
}

// Enable Restrictions
#pragma optimize("", on)