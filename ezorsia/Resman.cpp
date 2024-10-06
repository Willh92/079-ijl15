#include "stdafx.h"
#include "Resman.h"
#include <sys/stat.h>

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

// DWORD Address
auto g_rm = (void**)0x00BE2784;
auto g_root = (void**)0x00BE277C;
auto pNameSpace = 0x00BE1FC0;

// Disable Restrictions
#pragma optimize("", off)

BOOL Resman::Hook_InitializeResMan(BOOL bEnable) {

	CWvsApp__InitializeResMan_t Hook = [](void*) {

		// Generic
		void* pData = nullptr;
		void* pFileSystem = nullptr;
		void* pUnkOuter = 0;
		void* nPriority = 0;
		void* sPath;

		// Resman
		PcCreateObject_IWzResMan(L"ResMan", g_rm, pUnkOuter);

		void* pIWzResMan_Instance = *g_rm;
		auto IWzResMan__SetResManParam = *(void(__cdecl**)(void*, int, int, int))((*(int*)pIWzResMan_Instance) + 20); // Hard Coded
		IWzResMan__SetResManParam(pIWzResMan_Instance, RC_AUTO_REPARSE | RC_AUTO_SERIALIZE, -1, -1);

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

		struct stat sb;

		if (stat("./Data", &sb) == 0) {
			bstr_constructor(&sPath, pData, "./Data");
		}
		else {
			bstr_constructor(&sPath, pData, "../Data");
		}

		auto iDataFS = IWzFileSystem__Init(pFileSystem, pData, sPath);

		bstr_constructor(&sPath, pData, "/");

		auto mDataFS = IWZNameSpace__Mount(*g_root, pData, sPath, pFileSystem, nPriority);
		};

	return Memory::SetHook(bEnable, reinterpret_cast<void**>(&CWvsApp__InitializeResMan), Hook);
}

// Enable Restrictions
#pragma optimize("", on)