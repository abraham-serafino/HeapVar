#include <iostream>

using namespace std;

#define BITFIELD(x, y) byte y[x / 8 + (x % 8 > 0)]
#define SETBIT(x, y) (x[y / 8] |= (1 << (y % 8)))
#define CLEARBIT(x, y) (x[y / 8] ^= (1 << (y % 8)))
#define CHECKBIT(x, y) ((x[y / 8] & (1 << (y % 8))) > 0)
#define SIZEOF_BIT(x) 1
// @ TODO - add field-level bitwise operations & toInt()

int main(void) {
    BITFIELD(9, myBitField);

    // @TODO -
    //
    // 1) Transpiler should count the number of individual `bit`
    // variables (n) in a given scope.
    // 
    // 2) Create a BITFIELD(n) the same size as the number of `bit`
    // variables.
    //
    // 3) Store/retrieve the variables' values at/from their
    // respective locations in the BITFIELD.
    //
    // 4) Always return `1` from sizeof(bit) or sizeof(myBitVariable)

    // zero-initialization
    cout << CHECKBIT(myBitField, 0) << endl;
    cout << CHECKBIT(myBitField, 1) << endl;
    cout << CHECKBIT(myBitField, 3) << endl;
    cout << CHECKBIT(myBitField, 6) << endl;
    cout << CHECKBIT(myBitField, 9) << endl;
    // BEWARE - indexes wrap around
    cout << CHECKBIT(myBitField, 15) << endl;

    cout << endl;

    cout << (int) SETBIT(myBitField, 0) << endl;
    cout << (int) SETBIT(myBitField, 1) << endl;
    cout << (int) SETBIT(myBitField, 2) << endl;
    cout << (int) SETBIT(myBitField, 3) << endl;
    cout << (int) SETBIT(myBitField, 4) << endl;

    cout << endl;

    cout << (int) CLEARBIT(myBitField, 4) << endl;
    cout << (int) CLEARBIT(myBitField, 3) << endl;
    cout << (int) CLEARBIT(myBitField, 2) << endl;
    cout << (int) CLEARBIT(myBitField, 1) << endl;
    cout << (int) CLEARBIT(myBitField, 0) << endl;

    cout << endl;

    cout << CHECKBIT(myBitField, 0) << endl;
    SETBIT(myBitField, 0);
    cout << CHECKBIT(myBitField, 0) << endl;
    SETBIT(myBitField, 1);
    cout << CHECKBIT(myBitField, 1) << endl;
    SETBIT(myBitField, 2);
    cout << CHECKBIT(myBitField, 2) << endl;
    SETBIT(myBitField, 3);
    cout << CHECKBIT(myBitField, 3) << endl;
    SETBIT(myBitField, 4);
    cout << CHECKBIT(myBitField, 4) << endl;
}
