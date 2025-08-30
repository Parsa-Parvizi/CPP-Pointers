# Pointer Examples in C++

This program demonstrates various uses of pointers in C++, including:

- Pointer to a simple variable
- Pointer to an array
- Double pointers (pointer to pointer)
- Using pointers in functions (e.g., swapping values)
- Function pointers
- Dynamic memory allocation and pointer arithmetic

---

## Files

- `main.cpp` — Contains the full source code with examples and explanations.

---

## Features

### 1. Pointer to a Simple Variable
Shows how to declare a pointer to an integer variable, access and modify the variable's value through the pointer.

### 2. Pointer to an Array
Demonstrates how the name of an array acts as a pointer to its first element and how to iterate over the array using pointer arithmetic.

### 3. Double Pointer (Pointer to Pointer)
Illustrates the concept of a pointer that stores the address of another pointer, and how to access and modify the original variable through it.

### 4. Using Pointers in Functions
Includes a function `swapWithPointer` that swaps two integers by passing their addresses (pointers).

### 5. Function Pointers
Shows how to pass functions as arguments using function pointers, with examples of addition and multiplication.

### 6. Dynamic Memory Allocation
Demonstrates how to allocate an array dynamically on the heap, fill it with values, print it, and properly deallocate the memory.

---

## How to Compile and Run

Use a C++ compiler such as `g++`:

```bash
g++ -o pointer_examples main.cpp
./pointer_examples
