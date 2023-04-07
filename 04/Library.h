#pragma once
#include <Unknwn.h>


template <typename T>
class ComPtr {
    T* m_ptr = nullptr;
public:
    ComPtr() {}
    ~ComPtr() {
        if (m_ptr) {
            m_ptr->Release();
        }
    }
    T* operator -> () const {
        return m_ptr;
    }
    T** GetAddressOf() {
        return &m_ptr;
    }
};

struct __declspec(uuid("bc429c01-9f13-4b29-b3f2-b90be62578e5"))
IHen: IUnknown {
    virtual void __stdcall Cluck() = 0;
};

struct __declspec(uuid("c7c12279-b5c7-4d09-9a7b-5e932c4ee896"))
IHen2: IHen {
    virtual void __stdcall Forage() = 0;
};

struct __declspec(uuid("b23e146a-92aa-4c51-aedd-18a93922bc89"))
IOffline: IUnknown {
    virtual void __stdcall Load() = 0;
    virtual void __stdcall Save() = 0;
};

HRESULT __stdcall CreateHen(IHen ** hen);