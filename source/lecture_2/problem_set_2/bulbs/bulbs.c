// #include <cs50.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void) {
  char message[20];

  printf("Message: ");
  /*
  When using the scanf() function to read input from the user, spaces are
  considered as delimiters that separate the input into multiple tokens. This
  can cause problems when you want to read a string that contains spaces. To
  resolve this issue, you can use the fgets() function instead of scanf() to
  read the input as a string.
  */
  fgets(message, BITS_IN_BYTE, stdin);
  /*
  When you use the fgets() function to read input from the user, it reads a
  whole line of input, including any newline character (\n) at the end of the
  line. To remove the newline character from the end of the input, you can use
  the strcspn() function from the standard string library (string.h).
  */
  message[strcspn(message, "\n")] = '\0';

  for (int i = 0; i < strlen(message); i++) {
    int bit = 0;
    int ascii_code = (int)message[i];
    int binary[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    // for debugging purposes only
    // printf("ASCII code: %d\n", ascii_code);

    // convert ascii to binary
    while (ascii_code > 0) {
      binary[bit] = ascii_code % 2;
      ascii_code /= 2;
      bit++;
    }

    // for debugging purposes only
    // printf("Number of bits used: %d\n", bit);

    for (int j = 7; j >= 0; j--) {
      // printf("%d", binary[j]);
      print_bulb(binary[j]);
    }

    printf("\n");
  }
}

void print_bulb(int bit) {
  if (bit == 0) {
    // Dark emoji
    printf("\U000026AB");
  } else if (bit == 1) {
    // Light emoji
    printf("\U0001F7E1");
  }
}
