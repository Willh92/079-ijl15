#pragma once
#include "stdafx.h"
#undef  INTERFACE
#define INTERFACE   IWzCanvas 

  DECLARE_INTERFACE_(IWzCanvas, IWzSerialize) {
    BEGIN_INTERFACE

    // *** IUnknown methods ***
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppv) PURE;

    STDMETHOD_(ULONG, AddRef)(THIS) PURE;

    STDMETHOD_(ULONG, Release)(THIS) PURE;

    // ** IWzCanvas methods ***

    STDMETHOD(GetdefaultDither)(THIS_ CANVAS_DITHERTYPE*) PURE;

    STDMETHOD(PutdefaultDither)(THIS_ CANVAS_DITHERTYPE) PURE;

    STDMETHOD(GetdefaultLevelMap)(THIS_ CANVAS_LEVELMAP*) PURE;

    STDMETHOD(PutdefaultLevelMap)(THIS_ CANVAS_LEVELMAP) PURE;

    STDMETHOD(GetdefaultAllocator)(THIS_ IWzRawCanvasAllocator**) PURE;

    STDMETHOD(PutdefaultAllocator)(THIS_ IWzRawCanvasAllocator*) PURE;

    STDMETHOD(Create)(THIS_ unsigned int, unsigned int, tagVARIANT, tagVARIANT) PURE;

    STDMETHOD(AddRawCanvas)(THIS_ int, int, IWzRawCanvas*) PURE;

    STDMETHOD(GetrawCanvas)(THIS_ int, int, IWzRawCanvas**) PURE;

    STDMETHOD(GettileWidth)(THIS_ unsigned int*) PURE;

    STDMETHOD(GettileHeight)(THIS_ unsigned int*) PURE;

    STDMETHOD(Getwidth)(THIS_ unsigned int*) PURE;

    STDMETHOD(Putwidth)(THIS_ unsigned int) PURE;

    STDMETHOD(Getheight)(THIS_ unsigned int*) PURE;

    STDMETHOD(Putheight)(THIS_ unsigned int) PURE;

    STDMETHOD(GetpixelFormat)(THIS_ CANVAS_PIXFORMAT*) PURE;

    STDMETHOD(PutpixelFormat)(THIS_ CANVAS_PIXFORMAT) PURE;

    STDMETHOD(GetmagLevel)(THIS_ int*) PURE;

    STDMETHOD(PutmagLevel)(THIS_ int) PURE;

    STDMETHOD(GetSnapshotU)(THIS_ unsigned int*, unsigned int*, unsigned int*, unsigned int*, CANVAS_PIXFORMAT*, int*) PURE;

    STDMETHOD(GetSnapshot)(THIS_ int*, int*, int*, int*, CANVAS_PIXFORMAT*, int*) PURE;

    STDMETHOD(Getproperty)(THIS_ IWzProperty**) PURE;

    STDMETHOD(Getcx)(THIS_ int*) PURE;

    STDMETHOD(Putcx)(THIS_ int) PURE;

    STDMETHOD(Getcy)(THIS_ int*) PURE;

    STDMETHOD(Putcy)(THIS_ int) PURE;

    STDMETHOD(SetClipRect)(THIS_ int, int, int, int, tagVARIANT, tagVARIANT*) PURE;

    STDMETHOD(Copy)(THIS_ int, int, IWzCanvas*, tagVARIANT) PURE;

    STDMETHOD(CopyEx)(THIS_ int, int, IWzCanvas*, CANVAS_ALPHATYPE, int, int, int, int, int, int, tagVARIANT) PURE;

    STDMETHOD(Getpixel)(THIS_ int, int, unsigned int*) PURE;

    STDMETHOD(DrawRectangle)(THIS_ int, int, unsigned int, unsigned int, unsigned int) PURE;

    STDMETHOD(DrawLine)(THIS_ int, int, int, int, unsigned int, tagVARIANT) PURE;

    STDMETHOD(DrawPolygon)(THIS) PURE;

    STDMETHOD(DrawText)(THIS_ int, int, wchar_t*, IWzFont*, tagVARIANT, tagVARIANT, unsigned int*) PURE;

    END_INTERFACE
};