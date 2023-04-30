#include <stdio.h>

char* get_user_input();

int main(void)
{
    char name[] = "adrin";
    printf("hello, %s\n", name);

    int x = 5;
    int y = 8;

    if (x > y)
    {
        printf("x is greater than y\n");
    }
    else if (x < y)
    {
        printf("x is smaller than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }

    int n=10;
    while (n > 0)
    {
        printf("result: ");
        printf("%d \n", n);
        n--;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("for-loop result: ");
        printf("%d \n", i);
    }

    printf("vertical blocks\n");
    for (int i = 0; i < 3; i++)
    {
        printf("#\n");
    }

    printf("build a wall\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("#");
        }
        printf("\n");
    }

    char* input = get_user_input();

    printf("input: %s\n", input);   

    printf("program excited \n");
    return 0;
}

char* get_user_input()
{
    char* user_input;
    printf("read user input ...\n");
    scanf("%s", user_input);
    return user_input;
}