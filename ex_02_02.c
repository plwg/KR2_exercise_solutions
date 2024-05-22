#include <stdio.h>
#define MAXLINE 9999

int my_getline(char line[], int maxline);

int main()
{
    char line[MAXLINE];
    int len;

    while ((len = my_getline(line, MAXLINE)) > 0)
    {
        printf("%s", line);
    }

    for (int i = 0; i < MAXLINE; i++)
    {
        line[i] = '\0';
    }
}
int my_getline(char s[], int lim)
{
    int c;
    int i = 0;

    while (i < lim - 1)
    {
        c = getchar();

        if (c == '\n')
        {
            break;
        }
        if (c == EOF)
        {
            break;
        }
        s[i] = c;
        ++i;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}