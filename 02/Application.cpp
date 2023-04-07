#include "Library.h"

int main() {
    IHen * hen = CreateHen();
    hen->Cluck();
    {
        IOffline * offline = (IOffline *) hen->As("IOffline");
        if (offline) {
            offline->Load();
            offline->Release();
        }
    }
    hen->Release();
}