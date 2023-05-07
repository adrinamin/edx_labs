#include <stdio.h>

// Constant
const int N = 3;

// Prototype
float average(int length, int array[]);

int main(void)
{
    // Get scores
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scanf("Score: %i", &scores[i]);
    }

    // Print average
    printf("Average: %f\n", average(N, scores));
}

float average(int length, int array[]) // Not only can arrays be containers: They can be passed between functions.
{
    // Calculate average
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}