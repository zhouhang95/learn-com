#include "Library.h"
#include <stdio.h>
#include <string.h>
#include <new>

struct Hen : IHen2, IOffline {
    int ref_count = 0;
    Hen() {
        puts("Fuck ctor2");
    }
    ~Hen() {
        puts("Fuck dtor");
    }
    void __stdcall Cluck() {
        puts("Fuck Cluck");
    }
    void __stdcall Forage() {
        puts("Fuck Forage");
    }
    virtual ULONG __stdcall AddRef() {
        ref_count += 1;
        printf("Fuck AddRef %d\n", this->ref_count);
        return ref_count;
    }
    virtual ULONG __stdcall Release() {
        ref_count -= 1;
        printf("Fuck Release %d\n", this->ref_count);
        if (ref_count == 0) {
            delete this;
        }
        return ref_count;

    }

    virtual void __stdcall Load() {
        puts("Fuck load");
    }
    virtual void __stdcall Save() {
        puts("Fuck Save");
    }
    virtual HRESULT __stdcall QueryInterface(
        IID const &id,
        void **result
    ){
        if (
            __uuidof(IHen2) == id ||
            __uuidof(IHen) == id ||
            __uuidof(IUnknown) == id
        ) {
            *result = static_cast<IHen2*>(this);
        }
        else if (__uuidof(IOffline) == id) {
            *result = static_cast<IOffline*>(this);
        }
        else {
            *result = nullptr;
            return E_NOINTERFACE;
        }
        static_cast<IUnknown*>(*result)->AddRef();
        return S_OK;
    }

};

HRESULT __stdcall CreateHen(IHen ** result) {
    *result = new (std::nothrow) Hen();
    if (*result == 0) {
        return E_OUTOFMEMORY;
    }
    (*result)->AddRef();
    return S_OK;
}
