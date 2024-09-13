#include "stdafx.h"

// void __thiscall COutPacket::COutPacket(COutPacket *this, int nType)
// typedef VOID(__fastcall *_COutPacket__COutPacket_t)(COutPacket *pThis, PVOID edx, int nType);
// _COutPacket__COutPacket_t _COutPacket__COutPacket = reinterpret_cast<_COutPacket__COutPacket_t>(0x006EC9CE);
COutPacket::COutPacket(INT nType) {
    ((VOID(_fastcall * )(COutPacket * , PVOID, INT))
    0x006F5E40)(this, NULL, nType);
}


// void __thiscall COutPacket::Encode1(COutPacket *this, unsigned __int8 n)
// typedef VOID(__fastcall *_COutPacket__Encode1_t)(COutPacket *pThis, PVOID edx, unsigned __int8 n);
// _COutPacket__Encode1_t _COutPacket__Encode1 = reinterpret_cast<_COutPacket__Encode1_t>(0x00406549);
void COutPacket::Encode1(unsigned char n) {
    ((VOID(_fastcall * )(COutPacket * , PVOID, unsigned __int8))
    0x0040661F)(this, NULL, n);
}

// void __thiscall COutPacket::Encode4(COutPacket *this, unsigned int n)
// typedef VOID(__fastcall *_COutPacket__Encode4_t)(COutPacket *pThis, PVOID edx, unsigned int n);
// _COutPacket__Encode4_t _COutPacket__Encode4 = reinterpret_cast<_COutPacket__Encode4_t>(0x004065A6);
void COutPacket::Encode4(UINT n) {
    ((VOID(_fastcall * )(COutPacket * , PVOID, unsigned int))
    0x0040667C)(this, NULL, n);
}


// void __thiscall COutPacket::EncodeStr(COutPacket *this, ZXString<char> s)
// typedef VOID(__fastcall *_COutPacket__EncodeStr_t)(COutPacket *pThis, PVOID edx, ZXString<char> s);
// _COutPacket__EncodeStr_t _COutPacket__EncodeStr = reinterpret_cast<_COutPacket__EncodeStr_t>(0x0046F3CF);
void COutPacket::EncodeStr(ZXString<char> s) {
    ((VOID(_fastcall * )(COutPacket * , PVOID, ZXString<char>
    s))
    0x0046E6AE)(this, NULL, s);
}


// void __thiscall COutPacket::EncodeBuffer(COutPacket *this, const void *p, unsigned int uSize)
// typedef VOID(__fastcall *_COutPacket__EncodeBuffer_t)(COutPacket *pThis, PVOID edx, const void *p, unsigned int uSize);
// _COutPacket__EncodeBuffer_t _COutPacket__EncodeBuffer = reinterpret_cast<_COutPacket__EncodeBuffer_t>(0x0046C00C);
void COutPacket::EncodeBuffer(const void *p, unsigned int uSize) {
    ((VOID(_fastcall * )(COutPacket * , PVOID,
    const void *p,
    unsigned int uSize))
    0x0046B7F8)(this, NULL, p, uSize);
}

COutPacket::~COutPacket() {
    this->m_aSendBuff.RemoveAll();
}
