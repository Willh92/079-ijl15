#include "stdafx.h"
#include <IWzArchive.h>
#include <IWzSerialize.h>
#undef  INTERFACE
#define INTERFACE   IWzProperty

DECLARE_INTERFACE_(IWzProperty, IWzSerialize) {
	BEGIN_INTERFACE

	// *** IWzSerialize methods ***
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppv) PURE;

	STDMETHOD_(ULONG, AddRef)(THIS) PURE;

	STDMETHOD_(ULONG, Release)(THIS) PURE;

	STDMETHOD(GetpersistentUOL)(THIS_  wchar_t**) PURE;

	STDMETHOD(Serialize)(THIS_ IWzArchive*) PURE;

	// ** IWzProperty methods ***

	STDMETHOD(Getitem)(THIS_ wchar_t*, tagVARIANT*) PURE;

	STDMETHOD(Putitem)(THIS_ wchar_t*, tagVARIANT) PURE;

	STDMETHOD(GetNewEnum)(THIS_ IUnknown**) PURE;

	STDMETHOD(Getcount)(THIS_ unsigned int*) PURE;

	STDMETHOD(Add)(THIS_ wchar_t*, tagVARIANT, tagVARIANT) PURE;

	STDMETHOD(Remove)(THIS_ wchar_t*) PURE;

	STDMETHOD(Import)(THIS_ wchar_t*) PURE;

	END_INTERFACE
};