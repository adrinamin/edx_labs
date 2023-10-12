#include <stdio.h>
#include <stdlib.h>

// when you using too much memory, you can not change it afterwards
#define MAX_SIZE 100

typedef struct {
  int data[MAX_SIZE]; // drawback, it is fixed size
  int top;            // the size of the stack at the moment
} Stack;

void init(Stack *s) { s->top = -1; }

int is_empty(Stack *s) { return s->top == -1; }

int is_full(Stack *s) { return s->top == MAX_SIZE - 1; }

void push(Stack *s, int value) {
  if (is_full(s)) {
    printf("Stack overflow\n");
    exit(1);
  }
  s->data[++s->top] = value;
}

int pop(Stack *s) {
  if (is_empty(s)) {
    printf("Stack underflow\n");
    exit(1);
  }
  return s->data[s->top--];
}

int main() {
  Stack s;
  init(&s);

  push(&s, 1);
  push(&s, 2);
  push(&s, 3);

  // we retrieve the data in the reverse order
  printf("%d\n", pop(&s));
  printf("%d\n", pop(&s));
  printf("%d\n", pop(&s));

  return 0;
}
