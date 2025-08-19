#include <iostream>
#include <cassert>

using namespace std;

#define HEAP_VAR(typ, name, val) typ* name[] = { new typ(val) }
#define HEAP_REF(typ, name, target) typ** name = target
#define IS_NULL_HEAP(name) ((*name) == nullptr)

#define DEREF_HEAP(ptr) \
    ((ptr == nullptr || (*ptr) == nullptr) ? ( \
        cerr << endl << "Null reference exception" << endl,\
        exit(1),\
    (**ptr)) : (**ptr))

#define DELETE_HEAP(ptr) \
    if (ptr != nullptr && (*ptr) != nullptr) { \
        delete (*ptr); \
        (*ptr) = nullptr; \
    }

int main(void) {
    HEAP_VAR(double, myHeapVar, 21);
    HEAP_REF(double, myRef, myHeapVar);

    cout << DEREF_HEAP(myRef) << endl; // 21
    DEREF_HEAP(myRef) = 100;
    cout << DEREF_HEAP(myHeapVar) << endl; // 100

    DELETE_HEAP(myHeapVar);

    cout << (IS_NULL_HEAP(myRef) ? "true" : "false") << endl;
        // true
    DEREF_HEAP(myRef) = 100; // throws an exception
}
