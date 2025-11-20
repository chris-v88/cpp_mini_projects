#include <iostream>
using namespace std;

// LESSON: POINTERS AND REFERENCES IN C++

// Function that takes a POINTER as parameter
// A pointer is a variable that stores the memory address of another variable
void changeA(int* ptr){
    // The * operator is called the "dereference operator"
    // It accesses the value stored at the memory address that the pointer holds
    // Here we're changing the value at the address that ptr points to
    *ptr=20;
    cout << "Inside changeA(int* ptr): Changed value to " << *ptr << " at address " << ptr << endl;
}


// IMPORTANT OPERATORS:
// * = dereference operator (gets the value at an address)
// & = address-of operator (gets the address of a variable)

// Function overload that takes a REFERENCE as parameter
// A reference is an alias (another name) for an existing variable
// References must be initialized when declared and cannot be reassigned
void changeA(int &ref){
    // No special operator needed - ref is directly an alias for the original variable
    // Any changes to ref directly change the original variable
    ref=20;
    cout << "Inside changeA(int &ref): Changed value to " << ref << " (reference)" << endl;
}


int main(){
    cout << "=== C++ POINTERS AND REFERENCES LESSON ===" << endl << endl;

    // SECTION 1: BASIC POINTER DECLARATIONS AND USAGE
    cout << "1. BASIC POINTER DECLARATIONS:" << endl;
    
    // Declaring variables of different types
    int a1 = 100;
    int* ptr1 = &a1;    // ptr1 stores the ADDRESS of variable a1
    cout << "   int a1 = 100;" << endl;
    cout << "   int* ptr1 = &a1;  // ptr1 points to a1" << endl;
    cout << "   Value of a1: " << a1 << endl;
    cout << "   Address of a1: " << &a1 << endl;
    cout << "   Value stored in ptr1: " << ptr1 << endl;
    cout << "   Value pointed to by ptr1: " << *ptr1 << endl << endl;

    float a2 = 100.5;
    float* ptr2 = &a2;  // Different type - float pointer
    cout << "   float a2 = 100.5;" << endl;
    cout << "   float* ptr2 = &a2;" << endl;
    cout << "   Value of a2: " << a2 << endl;
    cout << "   Address stored in ptr2: " << ptr2 << endl;
    cout << "   Value pointed to by ptr2: " << *ptr2 << endl << endl;

    char ch = 'A';
    char* ptr3 = &ch;   // Character pointer
    cout << "   char ch = 'A';" << endl;
    cout << "   char* ptr3 = &ch;" << endl;
    cout << "   Value of ch: " << ch << endl;
    cout << "   Address stored in ptr3: " << (void*)ptr3 << endl; // Cast to void* to see address
    cout << "   Value pointed to by ptr3: " << *ptr3 << endl << endl;

    // SECTION 2: NULL POINTERS
    cout << "2. NULL POINTERS:" << endl;
    int* ptr = NULL;    // NULL pointer - doesn't point to any valid memory location
    cout << "   int* ptr = NULL;" << endl;
    cout << "   Value of ptr: " << ptr << endl;
    cout << "   This pointer doesn't point to any valid memory!" << endl << endl;

    // SECTION 3: POINTER ARITHMETIC
    cout << "3. POINTER ARITHMETIC:" << endl;
    int arr[5] = {10, 20, 30, 40, 50};
    int* arrPtr = arr;  // Points to first element
    cout << "   int arr[5] = {10, 20, 30, 40, 50};" << endl;
    cout << "   int* arrPtr = arr;" << endl;
    cout << "   arrPtr points to: " << *arrPtr << " (first element)" << endl;
    cout << "   arrPtr+1 points to: " << *(arrPtr+1) << " (second element)" << endl;
    cout << "   arrPtr+2 points to: " << *(arrPtr+2) << " (third element)" << endl << endl;

    // SECTION 4: FUNCTION CALLS WITH POINTERS AND REFERENCES
    cout << "4. FUNCTION CALLS - POINTERS vs REFERENCES:" << endl;
    
    int a = 10;
    cout << "   Original value of a: " << a << endl;

    // Call function with pointer - we pass the ADDRESS of 'a'
    cout << "   Calling changeA(&a) - passing address:" << endl;
    changeA(&a);    // Pass address of 'a' using & operator
    cout << "   Value of a after pointer call: " << a << endl << endl;

    // Reset value
    a = 10;
    cout << "   Reset a to: " << a << endl;
    
    // Call function with reference - we pass the VARIABLE itself
    cout << "   Calling changeA(a) - passing by reference:" << endl;
    changeA(a);     // Pass 'a' by reference (no & needed in call)
    cout << "   Value of a after reference call: " << a << endl << endl;

    // SECTION 5: REFERENCE EXAMPLES
    cout << "5. REFERENCE EXAMPLES:" << endl;
    int original = 42;
    int& refToOriginal = original;  // Reference must be initialized
    cout << "   int original = 42;" << endl;
    cout << "   int& refToOriginal = original;" << endl;
    cout << "   original = " << original << endl;
    cout << "   refToOriginal = " << refToOriginal << endl;
    
    refToOriginal = 100;  // Changes original too!
    cout << "   After refToOriginal = 100:" << endl;
    cout << "   original = " << original << endl;
    cout << "   refToOriginal = " << refToOriginal << endl << endl;

    // SECTION 6: CONST POINTERS
    cout << "6. CONST POINTERS:" << endl;
    int value1 = 15, value2 = 25;
    const int* ptrToConst = &value1;        // Pointer to constant int
    int* const constPtr = &value1;          // Constant pointer to int
    cout << "   const int* ptrToConst = &value1;  // Can change address, can't change value" << endl;
    cout << "   int* const constPtr = &value1;    // Can't change address, can change value" << endl;
    cout << "   *ptrToConst = " << *ptrToConst << endl;
    cout << "   *constPtr = " << *constPtr << endl << endl;

    // SECTION 7: DOUBLE POINTERS
    cout << "7. DOUBLE POINTERS (POINTER TO POINTER):" << endl;
    int x = 99;
    int* ptrToX = &x;
    int** ptrToPtrToX = &ptrToX;
    cout << "   int x = 99;" << endl;
    cout << "   int* ptrToX = &x;" << endl;
    cout << "   int** ptrToPtrToX = &ptrToX;" << endl;
    cout << "   x = " << x << endl;
    cout << "   *ptrToX = " << *ptrToX << endl;
    cout << "   **ptrToPtrToX = " << **ptrToPtrToX << endl << endl;

    // FINAL SUMMARY
    cout << "=== LESSON SUMMARY ===" << endl;
    cout << "• Pointers store memory addresses of variables" << endl;
    cout << "• Use & to get address of a variable" << endl;
    cout << "• Use * to get value at an address (dereference)" << endl;
    cout << "• References are aliases to existing variables" << endl;
    cout << "• References are safer and easier than pointers" << endl;
    cout << "• Pointers allow dynamic memory allocation and complex data structures" << endl;
    cout << "• Always initialize pointers before use!" << endl;

    return 0;
}