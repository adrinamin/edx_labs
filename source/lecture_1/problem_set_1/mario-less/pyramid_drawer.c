// #include <cs50.h> not using the cs50 library
// because implementing the problem set 1 with only public C libraries
#include <stdio.h>

// void drawLeftAlingedPyramid(int row, int height);
// void drawRightAlingedPyramid(int row, int empty, int height);

void drawLeftAlingedPyramid(int row, int height) {
  for (int i = 0; i < height; i++) {

    for (int j = 0; j < height - row; j++) {
      printf("#");
    }
    printf("\n");
    row--;
  }
}

void drawRightAlingedPyramid(int row, int empty, int height) {
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
}