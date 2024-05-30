// Test with cat ex_01_10.c | ./ex_01_10.o

#include <stdio.h>

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      printf("\\t");
    } else if (c == '\b') {
      printf("\\b");
    } else if (c == '\\') {
      printf("\\\\");
    } else {
      putchar(c);
    }
  }
  return 0;
}
