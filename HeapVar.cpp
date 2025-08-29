#include <iostream>
#include <string>

using namespace std;

struct Exception {
    char* message;

    Exception(char* _message) {
        message = _message;
    }
};

template <class T>
struct HeapVar {
    T* data;

    HeapVar& set (T& newValue) {
        if (!data) {
            data = new T;
        }

        *data = newValue;
        return *this;
    }

    T& get() const {
        if (data == nullptr) {
            throw Exception("Null reference exception!");
        }

        return *data;
    }

    void _delete() {
        delete data;
        data = nullptr;
    }
};

template <class T>
struct Ptr {
    bool isHeap = false;
    HeapVar<T>* heapData;
    T* data;

    Ptr () {
        // empty
    }

    Ptr (HeapVar<T>* newValue) {
        Ptr::operator=(newValue);
    }

    Ptr (T* newValue) {
        Ptr::operator=(newValue);
    }

    Ptr& operator= (HeapVar<T>* newValue) {
        isHeap = true;
        heapData = newValue;
        data = nullptr;
        return *this;
    }

    Ptr& operator= (T* newValue) {
        isHeap = false;
        heapData = nullptr;
        data = newValue;
        return *this;
    }

    Ptr& operator= (T newValue) {
        if (isHeap) {
            if (!heapData) {
                heapData = new HeapVar<T>();
            }

            (*heapData).set(newValue); 

        } else {
            if (data == nullptr) {
                throw Exception("Null reference exception!");
            }

            (*data) = newValue;
        }

        return *this;
    }

    T& operator*() const {
        if (isHeap) {
            if (heapData == nullptr) {
                throw Exception("Null reference exception!");
            }

            return (*heapData).get();

        } else {
            if (data == nullptr) {
                throw Exception("Null reference exception!");
            }

            return (*data);
        }
    }

    void _delete () {
        if (!isHeap) {
            data = nullptr;
            return;
        }

        if (heapData != nullptr && heapData->data != nullptr) {
            heapData->_delete();
            heapData = nullptr;
        }
    }

    bool isNull() {
        if (isHeap) {
            return heapData == nullptr || heapData->data == nullptr;
        } else {
            return data == nullptr;
        }
    }
};

int main() {
    Ptr<int> ptr = new HeapVar<int>(); // both of these will work
    ptr = new HeapVar<int>(); // both of these will work
    ptr = 33;

    Ptr<int> ptr2 = ptr;

    ptr2 = 30;
    cout << *ptr << endl; // 30

    ptr._delete();
    cout << (ptr.isNull() ? "true" : "false") << endl;

    try {
        cout << (*ptr) << endl;
    } catch (Exception e) {
        cout << e.message << endl;
    }

    ptr = 13;
    ptr = 31;

    ptr2._delete();
    ptr2 = 99;
    cout << (*ptr2) << endl; // 99

    int myVal = 100;
    ptr2 = &myVal;
    ptr2 = (*ptr2) + 50;
    cout << (*ptr2) << ", " << myVal << endl; // 150
    cout << (*ptr) << endl; // still 99

    ptr2._delete(); // delete non-heap reference
    cout << (ptr2.isNull() ? "true" : "false") << endl;

    try {
        cout << (*ptr2) << endl;
    } catch (Exception e) {
        cout << e.message << endl;
    }
}

//
// heap int $myInt = 33 // allocates memory for the value
// int $myRef = myInt   // myRef is a reference to myInt
//
// $myRef = 30          // dereference myRef
// stdout.print($myInt) // dereference myInt - 30
//
// myInt.delete()       // deallocates the memory
// stdout.print(myRef.isNull())
//      // the reference is also null
//
// stdout.print($myRef) // throws a Null Pointer Exception
//
// $myInt = 30          // allocates memory for the value again
// $myInt = 31          // dereference the new memory
// $myRef.delete()      // now both references are null again
// $myRef = 99          // allocates memory for the value again
//
// int myVal = 100
// myRef = myVal        // myRef is now a reference to myVal
// myRef = myRef + 50
// stdout.print(myRef)  // 150
// stdout.print(myVal)  // 150
// myRef.delete()       // does nothing to myVal, but myRef is null again
// strout.print($myVal) // null pointer exception
//
