#pragma once
#include "stdafx.h"

interface IWzCanvas;

#undef  INTERFACE
#define INTERFACE   IWzFont

DECLARE_INTERFACE_(IWzFont, IUnknown) {
    BEGIN_INTERFACE

        // *** IUnknown methods ***
        STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppv) PURE;

    STDMETHOD_(ULONG, AddRef)(THIS) PURE;

    STDMETHOD_(ULONG, Release)(THIS) PURE;

    // ** IWzFont methods ***

    STDMETHOD(Create)(THIS_ wchar_t*, unsigned int, unsigned int, tagVARIANT) PURE;

    STDMETHOD(Getcolor)(THIS_ int*) PURE;

    STDMETHOD(Getheight)(THIS_ int*) PURE;

    STDMETHOD(GetfullHeight)(THIS_ int*) PURE;

    STDMETHOD(CalcTextWidth)(THIS_ wchar_t*, tagVARIANT, unsigned int*) PURE;

    STDMETHOD(CalcLongestText)(THIS_ wchar_t*, int, tagVARIANT, int*) PURE;

    STDMETHOD(CalcLongestTextForGlobal)(THIS_ wchar_t*, int, tagVARIANT, int*) PURE;

    STDMETHOD(CalcLongestTextForGlobalEx)(THIS_ wchar_t*, int, int*, tagVARIANT, int*) PURE;

    STDMETHOD(CalcLineCountForGlobal)(THIS_ wchar_t*, int, tagVARIANT, int*) PURE;

    STDMETHOD(DrawText)(THIS_ int, int, wchar_t*, IWzCanvas*, tagVARIANT, tagVARIANT, unsigned int*) PURE;

    END_INTERFACE
};