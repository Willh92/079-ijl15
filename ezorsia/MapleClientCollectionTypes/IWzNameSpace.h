#pragma once
#include "stdafx.h"
#undef  INTERFACE
#define INTERFACE   IWzNameSpace

DECLARE_INTERFACE_IID_(IWzNameSpace, IUnknown, "2aeeeb36-a4e1-4e2b-8f6f-2e7bdec5c53d") {
    BEGIN_INTERFACE;

    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppv) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /*** IWzNameSpace methods ***/
    STDMETHOD(get_item)(THIS_ wchar_t*, tagVARIANT*) PURE;
    STDMETHOD(get_property)(THIS_ wchar_t*, tagVARIANT, IWzNameSpaceProperty**) PURE;
    STDMETHOD(get__NewEnum)(THIS_ IUnknown**) PURE;
    STDMETHOD(raw_Mount)(THIS_ wchar_t*, IWzNameSpace*, int) PURE;
    STDMETHOD(raw_Unmount)(THIS_ wchar_t*, tagVARIANT) PURE;
    STDMETHOD(raw__OnMountEvent)(THIS_ IWzNameSpace*, IWzNameSpace*, wchar_t*, int) PURE;
    STDMETHOD(raw__OnGetLocalObject)(THIS_ int, wchar_t*, int*, tagVARIANT*) PURE;

    END_INTERFACE;
};
_COM_SMARTPTR_TYPEDEF(IWzNameSpace, __uuidof(IWzNameSpace));