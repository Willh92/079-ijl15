
struct CInPacket {
    int m_bLoopback;
    int m_nState;
    ZArray<unsigned char> m_aRecvBuff;
    unsigned __int16
    m_uLength;
    unsigned __int16
    m_uRawSeq;
    unsigned __int16
    m_uDataLen;
    unsigned int m_uOffset;
};
