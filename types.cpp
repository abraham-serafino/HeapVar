// meaningful, system-independent type aliases
#include <iostream>
#include <cstdint>

using namespace std;

#define int8 int8_t
#define byte uint8_t
#define int16 int16_t
#define char16 char16_t
#define int int32_t
#define uint uint32_t
#define numeric double
#define ulong unsigned __int128 // may not exist on all systems
#define superlong __int128 // may not exist on all systems

int main(void) {
    cout << "bit: " << SIZEOF_BIT(myBitField[0]) << endl;
    cout << "int8: " << sizeof(int8) * 8 << endl;
    cout << "byte: " << sizeof(byte) * 8 << endl;
    cout << "bit[9]: " << sizeof(myBitField) * 8 << endl;
    cout << "int16: " << sizeof(int16) * 8 << endl;
    cout << "char16: " << sizeof(char16) * 8 << endl;
    cout << "int: " << sizeof(int) * 8 << endl;
    cout << "uint: " << sizeof(uint) * 8 << endl;
    cout << "double/numeric: " << sizeof(numeric) * 8;
    cout << " (value can be set to: " << -15.734 << ")" << endl;
    cout << "ulong: " << sizeof(ulong) * 8 << endl;
    cout << "superlong: " << sizeof(superlong) * 8 << endl;
}
