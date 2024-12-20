#pragma once
#include "stdafx.h"
#undef  INTERFACE
#define INTERFACE   IWzNameSpaceProperty

DECLARE_INTERFACE_IID_(IWzNameSpaceProperty, IUnknown, "a0b5164f-f89b-41b8-8264-15371fd02b4c") {
    BEGIN_INTERFACE;

    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppv) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /*** IWzNameSpaceProperty methods ***/
    STDMETHOD(get_item)(THIS_ wchar_t*, tagVARIANT*) PURE;
    STDMETHOD(get_name)(THIS_ wchar_t**) PURE;
    STDMETHOD(get_path)(THIS_ wchar_t**) PURE;
    STDMETHOD(get_size)(THIS_ tagVARIANT*) PURE;
    STDMETHOD(get_checksum)(THIS_ int*) PURE;
    STDMETHOD(get_property)(THIS_ wchar_t*, tagVARIANT*) PURE;

    END_INTERFACE;
};
_COM_SMARTPTR_TYPEDEF(IWzNameSpaceProperty, __uuidof(IWzNameSpaceProperty));