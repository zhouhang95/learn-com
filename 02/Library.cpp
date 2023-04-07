#include "Library.h"
#include <stdio.h>
#include <string.h>

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
    virtual void __stdcall AddRef() {
        ref_count += 1;
        printf("Fuck AddRef %d\n", this->ref_count);
    }
    virtual void __stdcall Release() {
        ref_count -= 1;
        printf("Fuck Release %d\n", this->ref_count);
        if (ref_count == 0) {
            delete this;
        }
    }

    virtual void __stdcall Load() {
        puts("Fuck load");
    }
    virtual void __stdcall Save() {
        puts("Fuck Save");
    }
    virtual void * __stdcall As(const char* type){
        if (
            strcmp(type, "IHen2") == 0 ||
            strcmp(type, "IHen") == 0 ||
            strcmp(type, "IObject") == 0
        ) {
            AddRef();
            return static_cast<IHen2*>(this);

        }
        else if (strcmp(type, "IOffline") == 0) {
            AddRef();
            return static_cast<IOffline*>(this);
        }
        else {
            return nullptr;
        }
    }

};

IHen * __stdcall CreateHen() {
    IHen * p = new Hen();
    p->AddRef();
    return p;
}
