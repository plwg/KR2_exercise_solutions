#include "print_binary.h"
#include <stdio.h>

void print_binary(unsigned n) {
  int bits = sizeof(n) * 8;

  for (int i = bits - 1; i >= 0; i--) {
    printf("%d", (n >> i) & 1);
  }
  printf("\n");
}