#include <iostream>
#include <cassert>
#include <unistd.h>

using namespace std;

#define HEAP_VAR(typ, name, val) typ* name[] = { new typ(val) }
#define HEAP_REF(typ, name, target) typ** name = target
#define IS_NULL_HEAP(name) ((*name) == nullptr)

#define DEREF_HEAP(ptr) \
    ((ptr == nullptr || (*ptr) == nullptr) ? ( \
        write(1, "\nNull reference exception\n", 25),\
        _exit(1),\
    (**ptr)) : (**ptr))

#define DELETE_HEAP(ptr) \
    if (ptr != nullptr && (*ptr) != nullptr) { \
        delete (*ptr); \
        (*ptr) = nullptr; \
    }

int main(void) {
    HEAP_VAR(double, myHeapVar, 21);
    HEAP_REF(double, myRef, myHeapVar);

    cout << DEREF_HEAP(myRef) << endl;
    DEREF_HEAP(myRef) = 100;
    cout << DEREF_HEAP(myHeapVar) << endl;

    DELETE_HEAP(myHeapVar);

    cout << (IS_NULL_HEAP(myRef) ? "true" : "false") << endl;
    DEREF_HEAP(myRef) = 100; // throws an exception
}
