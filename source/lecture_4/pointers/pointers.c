#include <stdio.h>

void change_value(int *nb);
void swap(int *n1, int *n2);
/*
POINTERS
main function: launches the main process
process memory layout (sections)
-------------------------------
stack -> local variables -> where the program is
heap -> dynamically allocated memory
.data -> initialized global variables
.text -> machine code
-------------------------------
- everything is a address
- pointers are variables that store addresses -> addresses to variables
- pointers are typed
- pointers are declared with *
- pointers are initialized with &
- pointers are dereferenced with *
- pointers can be NULL
- pointers can be reassigned
- pointers can be passed to functions
- pointers can be returned from functions
- pointers can be used to access array elements
- pointers can be used to access struct members
- pointers can be used to access memory on the heap
*/
int main(void)
{
    // declaration = instruction to the compiler to allocate memory (instruction manual -> "how to...."")
    int nb; // somewhere in memory 4 bytes are allocated
    // nb is allocated to a virtual address. OS does the mapping to physical address
    nb = 5;            // is a pointer to the address of nb
    change_value(&nb); // & -> giving the address of nb
    printf("nb: %d\n", nb);

    int a;
    int b;
    a = 5;
    b = 10;
    printf("a->%d, b->%d\n", a, b);
    swap(&a, &b);
    printf("a->%d, b->%d\n", a, b);

    return 0;
}

/*
is in a separate function frame
that's why it doesn't change the value of nb if we just pass nb
it is just changing a copy of the value of nb, not the actual value of nb
passed by value!! (copy of the value is passed)
This is why we need pointers!!!
passing value by reference
*/
void change_value(int *nb) // takes a pointer to an int nb
{
    // change the value of nb in the main function frame
    *nb = 10; // dereference the pointer to change the value of nb

    // declaration and dereferencing are identical
    // why? because the compiler knows that nb is a pointer
}

void swap(int *n1, int *n2)
{
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}
