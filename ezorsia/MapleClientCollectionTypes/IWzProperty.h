#pragma once
#undef  INTERFACE
#define INTERFACE   IWzProperty

DECLARE_INTERFACE_IID_(IWzProperty, IUnknown, "986515D9-0A0B-4929-8B4F-718682177B92")
{
	BEGIN_INTERFACE;

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppv) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	/*** IWzSerialize methods ***/
	STDMETHOD(get_persistentUOL)(THIS_ wchar_t**) PURE;
	STDMETHOD(raw_Serialize)(THIS_ uintptr_t*) PURE;

	/*** IWzProperty methods ***/
	STDMETHOD(get_item)(THIS_ const wchar_t* wsPath, _variant_t * result);
	STDMETHOD(put_item)(THIS_ const wchar_t* wsPath, _variant_t pItem);
	STDMETHOD(get__NewEnum)(THIS_ IUnknown**);
	STDMETHOD(get_count)(THIS_ unsigned int*);
	STDMETHOD(raw_Add)(THIS_ wchar_t*, tagVARIANT, tagVARIANT);
	STDMETHOD(raw_Remove)(THIS_ wchar_t*);
	STDMETHOD(raw_Import)(THIS_ wchar_t*);
	STDMETHOD(raw__GetHeadPosition)(THIS_ unsigned int**);
	STDMETHOD(raw__GetAt)(THIS_ unsigned int*, tagVARIANT*);
	STDMETHOD(raw__GetName)(THIS_ unsigned int*, wchar_t**);
	STDMETHOD(raw__GetNext)(THIS_ unsigned int**);

	template <typename T>
	T get_item(const wchar_t* wsPath)
	{
		_variant_t pItem(0);
		this->get_item(wsPath, &pItem);

		return reinterpret_cast<T>(pItem.ppunkVal);
	}

	VARIANTARG* get_item(const wchar_t* wsPath)
	{
		_variant_t pItem(0);
		this->get_item(wsPath, &pItem);

		return pItem.pvarVal;
	}

	VARIANTARG* get_item(const wchar_t* wsPath, VARIANTARG * dest)
	{
		this->get_item(wsPath, (_variant_t *)dest);
		return dest;
	}

	END_INTERFACE;
};