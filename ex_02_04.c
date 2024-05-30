#include <stdio.h>
#include <string.h>

void copy(char from[], char to[]);
void squeeze_one(char s[], int c);
void squeeze(char s1[], char s2[]);

int main()
{
    char s[100] = "This is the best of time; this is the worst of time.";
    char vowel[11] = "aeiouAEIOU";

    printf("%s\n", s);

    squeeze(s, vowel);

    printf("%s\n", s);

    return 0;
}

void squeeze_one(char s[], int c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

void copy(char from[], char to[])
{
    int i;
    for (i = 0; from[i] != '\0'; i++)
    {
        to[i] = from[i];
    }
    to[i] = '\0';
}

void squeeze(char s1[], char s2[])
{
    char c;
    char temp[strlen(s2) + 1];

    copy(s2, temp);

    while ((c = temp[0]) != '\0')
    {
        squeeze_one(s1, c);
        squeeze_one(temp, c);
    }
}