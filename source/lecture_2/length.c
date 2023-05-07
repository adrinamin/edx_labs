#include <stdio.h>

int main(void)
{
    // Prompt for user's name
    char* name;
    scanf("Name: %s", name);

    // Count number of characters up until '\0' (aka NUL character)
    int n = 0;
    while (name[n] != '\0')
    {
        n++;
    }
    printf("%i\n", n);
}