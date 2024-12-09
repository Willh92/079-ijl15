#pragma once
#include "stdafx.h"

#undef  INTERFACE
#define INTERFACE   IWzRawCanvas

DECLARE_INTERFACE_(IWzRawCanvas, IUnknown) {
	BEGIN_INTERFACE

		// *** IUnknown methods ***
		STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppv) PURE;

	STDMETHOD_(ULONG, AddRef)(THIS) PURE;

	STDMETHOD_(ULONG, Release)(THIS) PURE;

	// ** IWzRawCanvas methods ***

	STDMETHOD(GetpixelFormat)(THIS_ CANVAS_PIXFORMAT*) PURE;

	STDMETHOD(GetmagLevel)(THIS_ int*) PURE;

	STDMETHOD(Getwidth)(THIS_ unsigned int*) PURE;

	STDMETHOD(Getheight)(THIS_ unsigned int*) PURE;

	STDMETHOD(LockAddress)(THIS_ int*, tagVARIANT*) PURE;

	STDMETHOD(UnlockAddress)(THIS_ tagRECT*) PURE;

	STDMETHOD(SetTexture)(THIS_ unsigned int*) PURE;

	STDMETHOD(GetTextureSize)(THIS_ tagRECT*) PURE;

	END_INTERFACE
};