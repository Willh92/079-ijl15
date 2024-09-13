#pragma once

class COutPacket {
public:
    bool m_bLoopback;
    ZArray<unsigned char> m_aSendBuff;
    unsigned int m_uOffset;
    bool m_bIsEncryptedByShanda;

    explicit COutPacket(INT nType);
    ~COutPacket();

    VOID Encode1(unsigned __int8 n);
    VOID Encode4(UINT n);
    VOID EncodeStr(ZXString<char> s);
    VOID EncodeBuffer(const void *p, unsigned int uSize);
};