#include "stdafx.h"
#include <IWzArchive.h>
#undef  INTERFACE
#define INTERFACE   IWzSerialize

DECLARE_INTERFACE_(IWzSerialize, IUnknown) {
    BEGIN_INTERFACE

    // *** IUnknown methods ***
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppv) PURE;

    STDMETHOD_(ULONG, AddRef)(THIS) PURE;

    STDMETHOD_(ULONG, Release)(THIS) PURE;

    // ** IWzSerialize methods ***

    STDMETHOD(GetpersistentUOL)(THIS_  wchar_t**) PURE;

    STDMETHOD(Serialize)(THIS_ IWzArchive*) PURE;

    END_INTERFACE
};
