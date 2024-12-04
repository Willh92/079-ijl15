#pragma once
#undef  INTERFACE
#define INTERFACE   IWzVector2D

DECLARE_INTERFACE_IID_(IWzVector2D, IUnknown, "F28BD1ED-3DEB-4F92-9EEC-10EF5A1C3FB4")
{
	BEGIN_INTERFACE;

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppv) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;
	STDMETHOD(get_persistentUOL)(THIS_ wchar_t**) PURE;
	STDMETHOD(raw_Serialize)(THIS_ uintptr_t*) PURE;
	STDMETHOD(get_item)(THIS_ tagVARIANT, tagVARIANT*) PURE;
	STDMETHOD(get__NewEnum)(THIS_ IUnknown**) PURE;
	STDMETHOD(get_count)(THIS_ unsigned int*) PURE;
	STDMETHOD(get_x)(THIS_ int*) PURE;
	STDMETHOD(put_x)(THIS_ int) PURE;
	STDMETHOD(get_y)(THIS_ int*) PURE;
	STDMETHOD(put_y)(THIS_ int) PURE;
	STDMETHOD(get_x2)(THIS_ int*) PURE;
	STDMETHOD(put_x2)(THIS_ int) PURE;
	STDMETHOD(get_y2)(THIS_ int*) PURE;
	STDMETHOD(put_y2)(THIS_ int) PURE;
	STDMETHOD(raw_Move)(THIS_ int, int) PURE;
	STDMETHOD(raw_Offset)(THIS_ int, int) PURE;
	STDMETHOD(raw_Scale)(THIS_ int, int, int, int, int, int) PURE;
	STDMETHOD(raw_Insert)(THIS_ tagVARIANT, tagVARIANT) PURE;
	STDMETHOD(raw_Remove)(THIS_ tagVARIANT, tagVARIANT*) PURE;
	STDMETHOD(raw_Init)(THIS_ int, int) PURE;
	STDMETHOD(get_currentTime)(THIS_ int*) PURE;
	STDMETHOD(put_currentTime)(THIS_ int) PURE;
	STDMETHOD(get_origin)(THIS_ tagVARIANT*) PURE;
	STDMETHOD(put_origin)(THIS_ tagVARIANT) PURE;
	STDMETHOD(get_rx)(THIS_ int*) PURE;
	STDMETHOD(put_rx)(THIS_ int) PURE;
	STDMETHOD(get_ry)(THIS_ int*) PURE;
	STDMETHOD(put_ry)(THIS_ int) PURE;
	STDMETHOD(get_a)(THIS_ long double*) PURE;
	STDMETHOD(get_ra)(THIS_ long double*) PURE;
	STDMETHOD(put_ra)(THIS_ long double) PURE;
	STDMETHOD(get_flipX)(THIS_ int*) PURE;
	STDMETHOD(put_flipX)(THIS_ int) PURE;
	STDMETHOD(raw__GetSnapshot)(THIS_ int*, int*, int*, int*, int*, int*, long double*, long double*, tagVARIANT) PURE;
	STDMETHOD(raw_RelMove)(THIS_ int nX, int nY, _variant_t nTime, _variant_t nType) PURE;
	STDMETHOD(raw_RelOffset)(THIS_ int, int, tagVARIANT, tagVARIANT) PURE;
	STDMETHOD(raw_Ratio)(THIS_ IWzVector2D*, int, int, int, int) PURE;
	STDMETHOD(raw_WrapClip)(THIS_ tagVARIANT, int, int, unsigned int, unsigned int, tagVARIANT) PURE;
	STDMETHOD(raw_Rotate)(THIS_ long double, tagVARIANT) PURE;
	STDMETHOD(get_looseLevel)(THIS_ unsigned int*) PURE;
	STDMETHOD(put_looseLevel)(THIS_ unsigned int) PURE;
	STDMETHOD(raw_Fly)(THIS_ tagVARIANT*, int) PURE;

	int get_x()//
	{
		int x;
		this->get_x(&x);

		return x;
	}

	int get_y()
	{
		int y;
		this->get_y(&y);

		return y;
	}

	END_INTERFACE;
};