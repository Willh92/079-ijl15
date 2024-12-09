#pragma once
#undef  INTERFACE
#define INTERFACE   IWzUOL

DECLARE_INTERFACE_IID_(IWzUOL, IUnknown, "F945BF59-D1EC-45E8-8BD9-3DD11AC1A48A") {
    BEGIN_INTERFACE;

    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppv) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /*** IWzSerialize methods ***/
    STDMETHOD(get_persistentUOL)(THIS_ wchar_t**) PURE;
    STDMETHOD(raw_Serialize)(THIS_ IWzArchive*) PURE;

    /*** IWzUOL methods ***/
    STDMETHOD(raw_Init)(THIS_ wchar_t*, tagVARIANT) PURE;
    STDMETHOD(get_UOL)(THIS_ wchar_t**) PURE;
    STDMETHOD(put_UOL)(THIS_ wchar_t*) PURE;
    STDMETHOD(get_filePath)(THIS_ wchar_t**) PURE;
    STDMETHOD(get_className)(THIS_ wchar_t**) PURE;
    STDMETHOD(get_currentDirectory)(THIS_ wchar_t**) PURE;
    STDMETHOD(put_currentDirectory)(THIS_ wchar_t*) PURE;

    END_INTERFACE;
};