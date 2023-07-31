#include <stdio.h>

int main()
{
    /*
        & Provides the address of something stored in memory.
        * Instructs the compiler to go to a location in memory.
    */
    int a = 50;
    /*
        Notice the %p, which allows us to view the address of a location in memory.
        &n can be literally translated as “the address of n.”
        Executing this code will return an address of memory beginning with 0x.
    */
    printf("The address of a is %p.\n", &a);
    return 0;
}