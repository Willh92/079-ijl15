#pragma once
#include "stdafx.h"
#undef  INTERFACE
#define INTERFACE   IWzArchive

DECLARE_INTERFACE_(IWzArchive, IUnknown) {
    BEGIN_INTERFACE

    // *** IUnknown methods ***
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppv) PURE;

    STDMETHOD_(ULONG, AddRef)(THIS) PURE;

    STDMETHOD_(ULONG, Release)(THIS) PURE;

    // ** IWzArchive methods ***

    STDMETHOD(Getloading)(THIS_ int*) PURE;

    STDMETHOD(Read)(THIS_ unsigned __int8*, unsigned int, unsigned int*) PURE;

    STDMETHOD(Write)(THIS_ unsigned __int8*, unsigned int, unsigned int*) PURE;

    STDMETHOD(GetabsoluteUOL)(THIS_ wchar_t**) PURE;

    STDMETHOD(PutabsoluteUOL)(THIS_ wchar_t*) PURE;

    STDMETHOD(Getposition)(THIS_ unsigned int*) PURE;

    STDMETHOD(Getcontext)(THIS_ tagVARIANT*) PURE;

    STDMETHOD(Putcontext)(THIS_ tagVARIANT) PURE;

    END_INTERFACE
};