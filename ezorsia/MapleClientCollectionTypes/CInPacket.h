class CInPacket {
public:
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

public:
	CInPacket();
	CInPacket(CInPacket& in);
	CInPacket* operator= (const CInPacket& obj);
	~CInPacket();

public:
	char Decode1();
	short Decode2();
	unsigned long Decode4();
	int DecodeBuffer(PVOID out, int len);
	unsigned char* DecodeStr(ZXString<char>* p);
	int DecryptData(int unknow);

};
