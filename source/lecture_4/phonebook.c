#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // Open CSV file
    FILE *file = fopen("phonebook.csv", "a");

    // Get name and number
    char *name = malloc(50);
    char *number = malloc(50);

    printf("Name: ");
    scanf("%49s", name);
    printf("Number: ");
    scanf("%49s", number);

    // Print to file
    fprintf(file, "%s,%s\n", name, number);

    // Close file
    fclose(file);

    free(name);
    free(number);
}