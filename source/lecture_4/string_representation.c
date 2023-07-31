#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%s\n", s); // print the string
    printf("%p\n", s); // print the address of the string
    // print the address of each character in the string.
    printf("%p\n", &s[0]); // &s[0] is the same as s
    printf("%p\n", &s[1]); // &s[1] is the same as s + 1, which is the second character in the string
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);

    char *t = "hello!";
    printf("%c\n", *t);       // print the first character in the string
    printf("%c\n", *(t + 1)); // print the second character in the string
    printf("%c\n", *(t + 2)); // print the third character in the string
    printf("%c\n", *(t + 3)); // print the fourth character in the string

    // Get two strings
    char *s2 = "hello";
    char *t2 = "hello";

    // Print strings
    printf("%s\n", s2);
    printf("%s\n", t2);

    // print strings' addresses
    printf("%p\n", s2);
    printf("%p\n", t2);

    if (s2 == t2)
    {
        printf("equal\n");
    }

    return 0;
}