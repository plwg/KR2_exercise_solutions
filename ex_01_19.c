#include <stdio.h>

#define MAXLINE 9999

void reverse(char[], int len);
int my_getline(char line[], int maxline);

int main() {
  char line[MAXLINE];
  int len;

  while ((len = my_getline(line, MAXLINE)) > 0) {
    if (line[len - 1] == '\n') {
      reverse(line, len - 2);
    } else {
      reverse(line, len - 1);
    }
    printf("%s", line);

    for (int i = 0; i <= len; i++) {
      line[i] = '\0';
    }
  }
}

int my_getline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void reverse(char s[], int len) {
  int temp;
  for (int i = 0; i <= len / 2; ++i) {
    {
      temp = s[i];
      s[i] = s[len - i];
      s[len - i] = temp;
    }
  }
}