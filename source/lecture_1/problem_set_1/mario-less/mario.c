// #include <cs50.h> not using the cs50 library 
// because implementing the problem set 1 with only public C libraries
#include <stdio.h>

int main(void) 
{
    int height, row, empty;
    do {
        printf("Height: ");
        scanf("%d", &height);
    }while(height < 1 || height > 8); // todo: ASCII char check

    row = height - 1;
    empty = height -1;
    for (int i = 0; i < height; i++) {

        for (int e = 0; e < empty; e++) {
            printf(" ");
        }

        for (int j = 0; j < height - row; j++) {
            printf("#");
        }
        printf("\n");
        row--;
        empty--;
    }

    printf("Stored: %d\n", height);
        
    return 0;
}