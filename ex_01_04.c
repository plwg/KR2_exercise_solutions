#include <stdio.h>

int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;
  printf("%s %s\n", "CELSIUS", "FAHR");
  while (celsius <= upper) {
    fahr = celsius * (9.0 / 5.0) + 32.0;
    printf("%7.0f %4.0f\n", celsius, fahr);
    celsius = celsius + step;
  }

  return 0;
}
