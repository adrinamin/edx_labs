#include <stdio.h>

int get_starting_popultation()
{
    int starting_population;
    do {
    printf("read user input ...\n");
    scanf("%d", &starting_population);
    }while (starting_population < 9);
    printf("your starting population is %d\n", starting_population);
    return starting_population;
}

int get_ending_popultation(int starting_population)
{
    int ending_population;
    do {
    printf("read user input ...\n");
    scanf("%d", &ending_population);
    }while (ending_population < starting_population);
    printf("your ending population is %d\n", ending_population);
    return ending_population;
}

int calculate_years(int starting, int ending)
{
    int years = 0;
    double born = (double)starting / 3;
    double died = (double)starting / 4;
    double population = starting;
    while(population < ending) {
        double tmp = population + born - died;
        years++;
        if (tmp >= ending)
        {
            break;
        }
        population = tmp;
    }

    return years;
}

int main (void)
{
    int starting_population, ending_population;
    starting_population = get_starting_popultation();
    ending_population = get_ending_popultation(starting_population);
    return 0;
}