// Test with echo -en "abcd\naaaa\tdf" | ./ex_01_08.o

#include <stdio.h>

int main() {
  int c;

  double nb; // count of blank
  double nt; // count of tab
  double nn; // count of newline

  nb = nt = nn = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++nb;
    } else if (c == '\t') {
      ++nt;
    } else if (c == '\n') {
      ++nn;
    }
  }

  printf("%.0f\n", nb);
  printf("%.0f\n", nt);
  printf("%.0f\n", nn);

  return 0;
}
