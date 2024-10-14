#include "stdafx.h"

CInPacket::CInPacket()
{
}

CInPacket::~CInPacket()
{
}

CInPacket::CInPacket(
	CInPacket& in)
{
	((VOID(_fastcall*)(CInPacket*, PVOID, CInPacket&))
		0x006F5811)(this, NULL, in);
}

char CInPacket::Decode1()
{
	return 	((char(_fastcall*)(CInPacket*, PVOID))
		0x004066C9)(this, NULL);
}

short CInPacket::Decode2()
{
	return 	((short(_fastcall*)(CInPacket*, PVOID))
		0x004259A2)(this, NULL);
}

int CInPacket::Decode4()
{
	return 	((int(_fastcall*)(CInPacket*, PVOID))
		0x004066FF)(this, NULL);
}

int CInPacket::DecodeBuffer(PVOID out, int len) {
	return 	((int(_fastcall*)(CInPacket*, PVOID, PVOID, size_t))
		0x00431E77)(this, NULL, out, len);
}

unsigned char* CInPacket::DecodeStr(ZXString<char>* p) {
	return 	((unsigned char* (_fastcall*)(CInPacket*, PVOID, ZXString<char>*p))
		0x00471D7A)(this, NULL, p);
}