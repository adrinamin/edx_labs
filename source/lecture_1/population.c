#include <stdio.h>

int get_starting_popultation() {
  int starting_population;
  do {
    printf("Start size: ");
    scanf("%d", &starting_population);
  } while (starting_population < 9);
  return starting_population;
}

int get_ending_popultation(int starting_population) {
  int ending_population;
  do {
    printf("End size: ");
    scanf("%d", &ending_population);
  } while (ending_population < starting_population);
  return ending_population;
}

int calculate_years(int starting, int ending) {
  int years = 0;
  double population = starting;

  do {
    int born = population / 3;
    int died = population / 4;
    double tmp = population + (born - died);
    years++;
    if (tmp >= ending) {
      break;
    }
    population = tmp;
  } while (population < ending);

  return years;
}

int main(void) {
  int starting_population, ending_population, years;
  starting_population = get_starting_popultation();
  ending_population = get_ending_popultation(starting_population);
  years = calculate_years(starting_population, ending_population);
  printf("Years: %d \n", years);
  return 0;
}