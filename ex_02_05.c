#include <stdio.h>

int any(const char s1[], const char s2[]);

int main() {
  char s[] = "This is the best of time; this is the worst of time.";
  char vowel[] = "aeiouAEIOU";

  printf("%d", any(s, vowel));

  return 0;
}

int any(const char s1[], const char s2[]) {
  int i, j;
  int found = 0;

  for (i = 0; s1[i] != '\0'; i++) {
    for (j = 0; s2[j] != '\0'; j++) {
      if (s1[i] == s2[j]) {
        found = 1;
        break;
      }
    }
    if (found == 1) {
      break;
    }
  }

  if (found == 1) {
    return i;
  } else {
    return -1;
  }
}