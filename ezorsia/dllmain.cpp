// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "NMCO.h"
#include "ijl15.h"
#include "INIReader.h"
#include "ReplacementFuncs.h"
#include <comutil.h>
#include "BossHP.h"

void CreateConsole() {
	AllocConsole();
	FILE* stream;
	freopen_s(&stream, "CONOUT$", "w", stdout); //CONOUT$
}

std::string GetCurrentProcessName() {
	char buffer[MAX_PATH];
	DWORD size = GetModuleFileNameA(NULL, buffer, MAX_PATH);
	if (size == 0) {
		return "";
	}

	std::string processPath(buffer);
	size_t pos = processPath.find_last_of('\\');
	if (pos != std::string::npos) {
		return processPath.substr(pos + 1);
	}

	return "";
}

void Injected() {
	while (!Client::canInjected) {
		Sleep(10);
	}
	//Waitting fo Maplestory.exe load
	//HookCreateWindowExA(true); //default ezorsia
	//HookGetModuleFileName(true); //default ezorsia
	//HookPcCreateObject_IWzResMan(true);
	//HookPcCreateObject_IWzNameSpace(true);
	//HookPcCreateObject_IWzFileSystem(true);
	//HookCWvsApp__Dir_BackSlashToSlash(true);
	//HookCWvsApp__Dir_upDir(true);
	//Hookbstr_ctor(true);
	//HookIWzFileSystem__Init(true);
	//HookIWzNameSpace__Mount(true);
	//HookCWvsApp__InitializeResMan(false); //experimental //ty to all the contributors of the ragezone release: Client load .img instead of .wz v62~v92
	//Hook_StringPool__GetString(true); //hook stringpool modification //ty !! popcorn //ty darter
	//Hook_lpfn_NextLevel(true);
	////Hook_get_unknown(true);
	////Hook_get_resource_object(true); //helper function hooks  //ty teto for helping me get started
	////Hook_com_ptr_t_IWzProperty__ctor(true);
	////Hook_com_ptr_t_IWzProperty__dtor(true);
	//std::cout << "Applying resolution " << Client::m_nGameWidth << "x" << Client::m_nGameHeight << std::endl;
	std::string processName = GetCurrentProcessName();
	std::cout << "Current process name: " << processName << std::endl;
	Client::CRCBypass();
	Client::UpdateGameStartup();
	Client::UpdateResolution();
	Client::LongQuickSlot();
	//Client::FixMouseWheel();
	//Client::Chinese();
	//Client::FixDateFormat();
	//Client::FixItemType();
	Client::JumpCap();
	//Client::FixChatPosHook();
	Client::NoPassword();
	BossHP::Hook();
	Client::MoreHook();

	std::cout << "GetModuleFileName hook created" << std::endl;
	ijl15::CreateHook(); //NMCO::CreateHook();
	std::cout << "NMCO hook initialized" << std::endl;
	Client::injected = true;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
	{
		INIReader reader("config.ini");
		if (reader.ParseError() == 0) {
			Client::m_nGameWidth = reader.GetInteger("general", "width", 1280);
			Client::m_nGameHeight = reader.GetInteger("general", "height", 720);
			Client::MsgAmount = reader.GetInteger("general", "MsgAmount", 26);
			Client::CustomLoginFrame = reader.GetBoolean("general", "CustomLoginFrame", true);
			Client::WindowedMode = reader.GetBoolean("general", "WindowedMode", true);
			Client::RemoveLogos = reader.GetBoolean("general", "RemoveLogos", true);
			Memory::UseVirtuProtect = reader.GetBoolean("general", "UseVirtuProtect", true);
			Client::setDamageCap = reader.GetReal("optional", "setDamageCap", 199999);
			Client::setMAtkCap = reader.GetReal("optional", "setMAtkCap", 1999);
			Client::setAccCap = reader.GetReal("optional", "setAccCap", 999);
			Client::setAvdCap = reader.GetReal("optional", "setAvdCap", 999);
			Client::setAtkOutCap = reader.GetReal("optional", "setAtkOutCap", 199999);
			Client::useTubi = reader.GetBoolean("optional", "useTubi", false);
			Client::bigLoginFrame = reader.GetBoolean("general", "bigLoginFrame", false);
			Client::SwitchChinese = reader.GetBoolean("general", "SwitchChinese", false);
			Client::speedMovementCap = reader.GetInteger("optional", "speedMovementCap", 140);
			Client::jumpCap = reader.GetInteger("optional", "jumpCap", 123);
			Client::debug = reader.GetBoolean("debug", "debug", false);
			Client::ijl15hook = reader.GetBoolean("debug", "ijl15hook", false);
			Client::noPassword = reader.GetBoolean("debug", "noPassword", false);
			Client::imeType = reader.GetInteger("general", "imeType", 1);
			ownLoginFrame = reader.GetBoolean("optional", "ownLoginFrame", false);
			ownCashShopFrame = reader.GetBoolean("optional", "ownCashShopFrame", false);
			EzorsiaV2WzIncluded = reader.GetBoolean("general", "EzorsiaV2WzIncluded", true);
			Client::ServerIP_AddressFromINI = reader.Get("general", "ServerIP_Address", "127.0.0.1");
			Client::ServerIP_Address_hook = reader.GetBoolean("general", "ServerIP_Address_hook", true);
			Client::climbSpeedAuto = reader.GetBoolean("optional", "climbSpeedAuto", false);
			Client::climbSpeed = reader.GetFloat("optional", "climbSpeed", 1.0);
			Client::serverIP_Port = reader.GetInteger("general", "serverIP_Port", 8484);
			Client::talkRepeat = reader.GetBoolean("optional", "talkRepeat", false);
			Client::talkTime = reader.GetInteger("optional", "talkTime", 2000);
		}
		if(Client::debug)
			CreateConsole();	//console for devs, use this to log stuff if you want
		Hook_CreateMutexA(true); //multiclient //ty darter, angel, and alias!
		Hook_gethostbyname(true);
		CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(&Injected), NULL, 0, NULL);
		break;
	}
	default: break;
	case DLL_PROCESS_DETACH:
		ExitProcess(0);
	}
	return TRUE;
}