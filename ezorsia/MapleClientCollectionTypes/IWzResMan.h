#pragma once
#include "stdafx.h"
#undef  INTERFACE
#define INTERFACE   IWzResMan

DECLARE_INTERFACE_IID_(IWzResMan, IUnknown, "57dfe40b-3e20-4dbc-97e8-805a50f381bf") {
    BEGIN_INTERFACE;

    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppv) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /*** IWzResMan methods ***/
    STDMETHOD(get_rootNameSpace)(THIS_ IUnknown**) PURE;
    STDMETHOD(put_rootNameSpace)(THIS_ IUnknown*) PURE;
    STDMETHOD(raw_SetResManParam)(THIS_ int, int, int) PURE;
    STDMETHOD(raw_CreateObject)(THIS_ wchar_t*, IUnknown**) PURE;
    STDMETHOD(raw_GetObject)(THIS_ wchar_t*, tagVARIANT, tagVARIANT, tagVARIANT*) PURE;
    STDMETHOD(raw_SerializeObject)(THIS_ IWzArchive*, tagVARIANT, IUnknown**) PURE;
    STDMETHOD(raw_FlushCachedObjects)(THIS_ int) PURE;
    STDMETHOD(raw_OverrideObject)(THIS_ wchar_t*, wchar_t*) PURE;

    END_INTERFACE;
};
_COM_SMARTPTR_TYPEDEF(IWzResMan, __uuidof(IWzResMan));