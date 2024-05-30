#include <stdio.h>
#define MAXLINE 1000 // '\n' and '\0' will each take up one space

int getline_kr(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = getline_kr(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0) {
    printf("%s\n", longest);
  }
  printf("%d", max);
  return 0;
}

int getline_kr(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  int length = i;

  if (s[i - 1] != '\n' && s[i - 1] != EOF) {

    for (; (c = getchar()) != '\n' && c != EOF;) {
      length++;
    }
  }

  return length;
}

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}