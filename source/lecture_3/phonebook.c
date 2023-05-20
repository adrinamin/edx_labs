#include <stdio.h>
#include <string.h>

typedef struct {
  char *name;
  char *number;
} person;

int main(void) {
  char name[25];
  person people[2];

  people[0].name = "Carter";
  people[0].number = "+1-617-495-1000";

  people[1].name = "David";
  people[1].number = "+1-949-468-2750";

  // Search for name
  printf("Name: ");
  scanf("%24[^\n]", name);

  printf("go through names...\n");
  for (int i = 0; i < 2; i++) {
    if (strcmp(people[i].name, name) == 0) {
      printf("Found %s\n", people[i].number);
      return 0;
    }
  }
  printf("Not found\n");
  return 1;
}