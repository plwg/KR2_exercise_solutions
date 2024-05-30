/*
1. Tested zero lenght input
2. Tested moby dick
*/
#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

/* counts lines, words and characters as input */

int main() {
  unsigned int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);

  return 0;
}