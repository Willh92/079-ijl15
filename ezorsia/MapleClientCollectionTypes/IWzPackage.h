#pragma once
#include "stdafx.h"
#undef  INTERFACE
#define INTERFACE   IWzPackage

DECLARE_INTERFACE_IID_(IWzPackage, IWzNameSpace, "e610818b-038d-4522-9232-30fcd5f4737c") {
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

    /*** IWzPackage methods ***/
    STDMETHOD(raw_Init)(THIS_ wchar_t*, wchar_t*, IWzSeekableArchive*) PURE;

    END_INTERFACE;
};
_COM_SMARTPTR_TYPEDEF(IWzPackage, __uuidof(IWzPackage));