#pragma once
#include "stdafx.h"

#undef  INTERFACE
#define INTERFACE   IWzRawCanvasAllocator

DECLARE_INTERFACE_(IWzRawCanvasAllocator, IUnknown) {
    BEGIN_INTERFACE

        // *** IUnknown methods ***
        STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppv) PURE;

    STDMETHOD_(ULONG, AddRef)(THIS) PURE;

    STDMETHOD_(ULONG, Release)(THIS) PURE;

    // ** IWzRawCanvasAllocator methods ***

    STDMETHOD(AllocCanvas)(THIS_ IWzCanvas*, CANVAS_PIXFORMAT, int) PURE;

    STDMETHOD(ConvertIfNotAvailable)(THIS_ IWzCanvas*, int*) PURE;

    END_INTERFACE
};