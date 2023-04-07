#include "Library.h"

int main() {
    ComPtr<IHen> hen;
    if (S_OK == CreateHen(hen.GetAddressOf())) {
        hen->Cluck();
        ComPtr<IOffline> offline;
        if (S_OK == hen->QueryInterface(__uuidof(IOffline), reinterpret_cast<void **>(offline.GetAddressOf()))) {
            offline->Load();
        }
    }
}