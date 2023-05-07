#include <stdio.h>
#include "pyramid_drawer.h"

int main(void) {
  char input;
  int height, row, empty;
  do {
    printf("Height: ");
    scanf("%s", &input);
    if (input < '0' || input > '9') {
      height = 0;
      continue;
    }

    height = input - '0';

  } while (height < 1 || height > 8); // todo: ASCII char check

  row = height - 1;
  empty = height - 1;

  //   drawLeftAlingedPyramid(row, height);
  drawRightAlingedPyramid(row, empty, height);

  printf("Stored: %d\n", height);
  
  return 0;
}