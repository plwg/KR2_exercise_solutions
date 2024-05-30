#include <stdio.h>

float conversion_from_fahr_to_celsius(float fahr);

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version */
int main() {
  float fahr;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("%s %s\n", "FAHR", "CELSIUS");
  while (fahr <= upper) {
    printf("%4.0f %7.1f\n", fahr, conversion_from_fahr_to_celsius(fahr));
    fahr = fahr + step;
  }

  return 0;
}

float conversion_from_fahr_to_celsius(float fahr) {
  return (5.0 / 9.0) * (fahr - 32.0);
}
