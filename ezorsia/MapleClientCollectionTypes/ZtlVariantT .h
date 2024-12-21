#pragma once
#include <comdef.h>

class Ztl_variant_t : public tagVARIANT {
public:
    inline Ztl_variant_t() {
        VariantInit(this);
    }
    inline Ztl_variant_t(int lSrc, VARTYPE vtSrc) {
        reinterpret_cast<void(__thiscall*)(Ztl_variant_t*, int, VARTYPE)>(0x004031B5)(this, lSrc, vtSrc);
    }
    inline ~Ztl_variant_t() {
        reinterpret_cast<void(__cdecl*)(Ztl_variant_t*)>(0x004029B7)(this);
    }
    inline IUnknown* GetUnknown(bool fAddRef, bool fTryChangeType) {
        return reinterpret_cast<IUnknown * (__thiscall*)(Ztl_variant_t*, bool, bool)>(0x004032B2)(this, fAddRef, fTryChangeType);
    }
};