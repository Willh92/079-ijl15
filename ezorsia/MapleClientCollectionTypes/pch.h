// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

//#ifndef PCH_H
//#define PCH_H

#include "framework.h"

#include <atlstr.h>
#include "unknwn.h"

#include "comip.h"
#include "comdef.h"
#include "asserts.h"
#include "logger.h"
#include <intrin.h>
#include <mutex>
#include <thread>
#include <heapapi.h>

#include "ZXString.h"
#include "ZAllocBase.h"
#include "ZAllocAnonSelector.h"
#include "ZAllocStrSelector.h"
#include "ZFatalSection.h"
#include "ZAllocEx.h"
#include "ZArray.h"
#include "ZRefCounted.h"
#include "ZRefCountedAccessor.h"
#include "ZRecyclableAvBuffer.h"
#include "ZRecyclable.h"
#include "ZRefCountedDummy.h"
#include "ZRef.h"
#include "ZMap.h"
#include "ZList.h"

#include "ZInetAddr.h"
#include "ZSocketBuffer.h"
#include "ZSocketBase.h"
#include "COutPacket.h"
#include "CClientSocket.h"
#include "TSecType.h"


#include "TSingleton.h"