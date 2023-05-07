#include <stdio.h>

int main(void)
{
    for (int i = 0; i <= 3; i++) // for (int i = 0; i < 3; i++) is the correct solution
    {
        printf("i is %i\n", i); // <- for debugging purposes
        printf("#\n");
    }
}