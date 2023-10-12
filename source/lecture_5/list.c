#include <stdio.h>
#include <stdlib.h>

void inefficientList(void) {
  // inefficient way of storing numbers
  int list[3];

  // Initialize list of size 3 with numbers
  list[0] = 1;
  list[1] = 2;
  list[2] = 3;

  // Print list
  for (int i = 0; i < 3; i++) {
    printf("%i\n", list[i]);
  }
}

int efficientList(void) {
  // chunk of contiguous memory
  int *list = malloc(3 * sizeof(int));

  // check if malloc was successful
  if (list == NULL) {
    return 1;
  }

  // Initialize list of size 3 with numbers
  list[0] = 1; // *list = 1;
  list[1] = 2; // *(list + 1) = 2;
  list[2] = 3; // *(list + 2) = 3;

  for (int i = 0; i < 3; i++) {
    printf("%i\n", list[i]);
  }

  // no erorrs
  return 0;
}

int increaseListByOne(void) {
  // chunk of contiguous memory
  int *list = malloc(3 * sizeof(int));
  // check if malloc was successful
  if (list == NULL) {
    return 1;
  }

  // Initialize list of size 3 with numbers
  list[0] = 1; // *list = 1;
  list[1] = 2; // *(list + 1) = 2;
  list[2] = 3; // *(list + 2) = 3;

  // List of size 4
  // assign to temp and not list variable
  // because otherwise it would lead to a memory leak
  int *tmp = malloc(4 * sizeof(int));
  // check if malloc was successful
  if (tmp == NULL) {
    free(list); // avoid memory leak
    return 1;
  }

  // Copy list of size 3 into list of size 4
  for (int i = 0; i < 3; i++) {
    tmp[i] = list[i];
  }

  // Add number to list of size 4
  tmp[3] = 4;

  // Free list of size 3
  free(list);

  // Remember list of size 4
  list = tmp;

  // Print list
  for (int i = 0; i < 4; i++) {
    printf("%i\n", list[i]);
  }

  // Free list
  free(list); // avoid memory leak
  // free(tmp); // would also be possible but not necessary
  return 0;
}

int usingBuiltInFunctionality(void) {
  // List of size 3
  int *list = malloc(3 * sizeof(int));
  if (list == NULL) {
    return 1;
  }

  // Initialize list of size 3 with numbers
  list[0] = 1;
  list[1] = 2;
  list[2] = 3;

  // Resize list to be of size 4
  // using a tmp variable to avoid memory leak
  int *tmp = realloc(list, 4 * sizeof(int));
  if (tmp == NULL) {
    free(list);
    return 1;
  }
  list = tmp;

  // Add number to list
  list[3] = 4;

  // Print list
  for (int i = 0; i < 4; i++) {
    printf("%i\n", list[i]);
  }

  // Free list
  free(list);
  return 0;
}

int main(void) {
  printf("Inefficient list:\n");
  inefficientList();
  printf("Efficient list:\n");
  efficientList();
  printf("Increase list by one:\n");
  increaseListByOne();
  printf("Using built-in functionality:\n");
  usingBuiltInFunctionality();

  return 0;
}