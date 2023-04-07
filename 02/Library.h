#pragma once

struct IObject {
    virtual void __stdcall AddRef() = 0;
    virtual void __stdcall Release() = 0;
    virtual void * __stdcall As(const char* type) = 0;
};

struct IHen: IObject {
    virtual void __stdcall Cluck() = 0;
};

struct IHen2: IHen {
    virtual void __stdcall Forage() = 0;
};

struct IOffline: IObject {
    virtual void __stdcall Load() = 0;
    virtual void __stdcall Save() = 0;
};

IHen * __stdcall CreateHen();