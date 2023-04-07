#include <Windows.h>

int main() {
    struct __declspec(uuid("4b9cf523-7cea-4d70-8c42-451694900c34")) TypeNmae;
    GUID guid2 = __uuidof(TypeNmae);
    return 0;
}