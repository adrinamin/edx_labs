#include <stdio.h>

int main(void)
{
    int n;
    // An array of integers
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};
    // Search for number
    printf("Please enter a number: ");
    scanf("%d", &n);

    // go through all elements of the array
    // and check if n is inside the array
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}