#include "stdafx.h"
#include "ijl15.h"
#include "ijl.h" 


#ifdef IJL_MT

void ijl15::CreateHook() {
}

extern "C"  const IJLibVersion* __stdcall ijlGetLibVersionWrapper() {
	return ijlGetLibVersion();
}

extern "C"   IJLERR __stdcall ijlInitWrapper(JPEG_CORE_PROPERTIES* jcprops) { return ijlInit(jcprops); }

extern "C"  IJLERR __stdcall ijlFreeWrapper(JPEG_CORE_PROPERTIES* jcprops) { return ijlFree(jcprops); }

extern "C"  IJLERR __stdcall ijlReadWrapper(JPEG_CORE_PROPERTIES* jcprops, IJLIOTYPE iotype) {
	return ijlRead(jcprops, iotype);
}

extern "C"  IJLERR __stdcall ijlWriteWrapper(JPEG_CORE_PROPERTIES* jcprops, IJLIOTYPE iotype) {
	return ijlWrite(jcprops, iotype);
}

extern "C"  const char* __stdcall ijlErrorStrWrapper(IJLERR code) { return ijlErrorStr(code); }

#else

void(*ijlErrorStr_Proc) = ijlErrorStr;
void(*ijlFree_Proc) = ijlFree;
void(*ijlGetLibVersion_Proc) = ijlGetLibVersion;
void(*ijlInit_Proc) = ijlInit;
void(*ijlRead_Proc) = ijlRead_Proc;
void(*ijlWrite_Proc) = ijlWrite;

void ijl15::CreateHook() {
	if (Client::ijl15hook) {
		HMODULE hModule = LoadLibraryA("2ijl15.dll");
		if (hModule == nullptr) {
			MessageBox(NULL, L"Failed to find 2ijl15.dll file", L"Missing file", 0);
			return;
		}
		ijlErrorStr_Proc = GetProcAddress(hModule, "ijlErrorStr");
		ijlFree_Proc = GetProcAddress(hModule, "ijlFree");
		ijlGetLibVersion_Proc = GetProcAddress(hModule, "ijlGetLibVersion");
		ijlInit_Proc = GetProcAddress(hModule, "ijlInit");
		ijlRead_Proc = GetProcAddress(hModule, "ijlRead");
		ijlWrite_Proc = GetProcAddress(hModule, "ijlWrite");
	}
}

extern "C"  __declspec(naked) void ijlGetLibVersionWrapper()
{
	__asm	jmp dword ptr[ijlGetLibVersion_Proc] // make sure you're compiling in x86
}

extern "C"  __declspec(naked) void ijlInitWrapper()
{
	__asm	jmp dword ptr[ijlInit_Proc]
}

extern "C"  __declspec(naked) void ijlFreeWrapper()
{
	__asm	jmp dword ptr[ijlFree_Proc]
}

extern "C"  __declspec(naked) void ijlReadWrapper()
{
	__asm	jmp dword ptr[ijlRead_Proc]
}

extern "C" __declspec(naked) void ijlWriteWrapper()
{
	__asm	jmp dword ptr[ijlWrite_Proc]
}

extern "C" __declspec(naked) void ijlErrorStrWrapper()
{
	__asm	jmp dword ptr[ijlErrorStr_Proc]
}

#endif