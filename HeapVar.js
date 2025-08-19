// Everything is already stored on the heap in Javascript;
// but, this still provides a way to create references to
// arbitrary values that are automatically null'ed out when
// the original value is destroyed.

// Unfortunately, Javascript does not have a macro system.

// I've separated out the utility code into functions for
// readability, but our transpiler will probably just insert
// it inline.

// We want to avoid creating and calling functions, because
// it takes up space and time inside the interpreter.

function DEREF_HEAP (ptr) {
    return ptr?.[0]?.[0];
}

function DEREF_HEAP_SET (ptr, value) {
    if (ptr?.[0]?.[0]) {
        ptr[0][0] = value;
    } else {
        throw Error("Null reference exception.");
    }
};

function DELETE_HEAP (ptr) {
    if (ptr?.[0] !== null) {
        ptr[0] = null;
    }
};

function IS_NULL_HEAP (ptr) {
    ptr?.[0] == null;
}

(function main() {
    // heap myHeapVar := 21
    let myHeapVar = [[21]];

    // $myRef := myHeapVar
    let myRef = myHeapVar;

    // stdout.writeln($myRef)
    console.log(DEREF_HEAP(myRef));
    // $myRef = 100
    DEREF_HEAP_SET(myRef, 100);
    // stdout.writeln($myHeapVar)
    console.log(DEREF_HEAP(myHeapVar));

    // myHeapInt.delete()
    DELETE_HEAP(myHeapVar);
    // stdout.writeln(myRef.isNull)
    console.log(IS_NULL_HEAP(myRef));

    // throws a null reference exception
    DEREF_HEAP_SET(myRef, 100);
})()
