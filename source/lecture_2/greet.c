#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char name[20]; // allocate space for up to 19 characters plus a null terminator
  printf("What's your name? ");
  scanf("%19s", name); // read up to 19 characters to avoid buffer overflow
  printf("hello, %s\n", name);
  printf("Your name has %lu characters. \n", strlen(name));

  if (argc == 2) {
    printf("hello %s\n", argv[1]); // get the second argument from the command line.
  }

  return 0; // exit status
}