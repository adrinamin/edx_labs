#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Get a string
    char *s = malloc(100);
    if (s == NULL)
    {
        printf("MEMORY allocation failed.\n");
        return 1;
    }

    printf("s: ");
    scanf("%99s", s);
    printf("\n");

    // Copy string's address
    char *t = s;

    // Capitalize first letter in string
    if (strlen(t) > 0) // check to avoid segmentation fault
    {
        t[0] = toupper(t[0]);
    }

    // Print string twice
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(s);

    return 0;
}

/*
Avoiding segementation faut:
The segmentation fault occurs because you are trying to read a string into a pointer s,
but s is not pointing to a valid memory location.
In C, when you declare a pointer, it doesn't automatically point to any valid memory address.
You must allocate memory for the pointer before using it to store data.
*/