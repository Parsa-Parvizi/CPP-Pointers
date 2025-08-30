#include <iostream>
using namespace std;

// Function to swap two integers using pointers
void swapWithPointer(int* a, int* b) {
    int temp = *a;   // Read the value pointed by a
    *a = *b;         // Assign the value pointed by b to the location pointed by a
    *b = temp;       // Assign temp to the location pointed by b
}

// Function that receives an array via pointer and prints its elements
void printArray(int* arr, int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";  // arr[i] = *(arr + i)
    }
    cout << endl;
}

// Functions to be used with function pointers
int add(int a, int b) {
    return a + b;
}
int multiply(int a, int b) {
    return a * b;
}

// Function that takes a function pointer as parameter and applies it to x and y
void calculate(int x, int y, int (*func)(int, int)) {
    cout << "Result: " << func(x, y) << endl;
}

// Additional function to demonstrate pointer arithmetic and dynamic memory
void dynamicArrayExample(int size) {
    int* dynArr = new int[size];  // dynamically allocate array
    for (int i = 0; i < size; i++) {
        dynArr[i] = i * i;  // fill with squares
    }
    cout << "Dynamic array elements: ";
    for (int i = 0; i < size; i++) {
        cout << dynArr[i] << " ";
    }
    cout << endl;
    delete[] dynArr;  // free allocated memory
}

int main() {
    // 1. Pointer to a simple variable
    int x = 10;
    int* ptr = &x;  // ptr holds the address of x
    cout << "x = " << x << ", *ptr = " << *ptr << endl;

    *ptr = 20;  // change value of x through pointer
    cout << "After *ptr = 20 -> x = " << x << endl;

    // 2. Pointer to an array
    int arr[5] = {1, 2, 3, 4, 5};
    int* pArr = arr;  // array name is pointer to first element
    printArray(pArr, 5);

    // 3. Pointer to pointer (double pointer)
    int y = 50;
    int* pY = &y;
    int** ppY = &pY;
    cout << "y = " << y << ", *pY = " << *pY << ", **ppY = " << **ppY << endl;

    **ppY = 100; // change y through double pointer
    cout << "After **ppY = 100 -> y = " << y << endl;

    // 4. Using pointers in functions (swap two integers)
    int a = 5, b = 10;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swapWithPointer(&a, &b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    // 5. Function pointer usage
    calculate(5, 3, add);       // outputs 8
    calculate(5, 3, multiply);  // outputs 15

    // 6. Demonstrate dynamic memory allocation and pointer arithmetic
    dynamicArrayExample(7);

    return 0;
}
