#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int my_getline(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main()
{
    char line[MAXLINE];
    int index;

    while (my_getline(line, MAXLINE) > 0)
    {
        if ((index = strindex(line, pattern)) >= 0)
        {
            printf("%d ", index);
            printf("%s", line);
        }
        if ((index = strrindex(line, pattern)) >= 0)
        {
            printf("%d ", index);
            printf("%s", line);
        }
    }
    return 0;
}

int my_getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

int strrindex(char s[], char t[])
{
    int i, j, k;

    int s_len = strlen(s);
    int t_len = strlen(t);

    for (i = s_len - 1; i > 0; i--)
    {
        for (j = i, k = t_len - 1; k > 0 && s[j] == t[k]; j--, k--)
        {
            ;
        }
        if (k == 0)
        {
            return i - t_len + 1;
        }
    }
    return -1;
}

int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
        {
            ;
        }
        if (k > 0 && t[k] == '\0')
        {
            return i;
        }
    }
    return -1;
}
