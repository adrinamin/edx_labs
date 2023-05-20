#include <stdio.h>

void draw(int n);

int main(void)
{
    int height;
    printf("Height: ");
    scanf("%d", &height);
    draw(height);
}

void draw(int n)
{
    // nothing to draw
    // ensures that the code does not run forever
    if (n <= 0)
    {
        return;
    }

    // draw pyramid of height n - 1
    draw(n - 1);

    // Draw one more row of width n
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}