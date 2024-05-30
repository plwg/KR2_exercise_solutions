#include <math.h>
#include <stdio.h>
#include <string.h>
#define MAXLINE 9999

long htoi(const char s[]);

int main()
{
    int i, c;
    long res;
    char s[MAXLINE + 1];

    for (i = 0; i < (MAXLINE - 1) && (c = getchar()) != '\n' && c != EOF; i++)
    {
        s[i] = c;
    }

    s[++i] = '\0';

    res = htoi(s);

    printf("%ld", res);

    return 0;
}

long htoi(const char s[])
{
    long unsigned len = strlen(s);
    long res = 0L;
    int hex_digit;

    for (long i = len - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            hex_digit = s[i] - '0';
            res += (hex_digit) * (long)pow((double)16, (double)len - i - 1);
        }
        else if (s[i] >= 'a' && s[i] <= 'f')
        {
            hex_digit = s[i] - 'a' + 10;
            res += (hex_digit) * (long)pow((double)16, (double)len - i - 1);
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            hex_digit = s[i] - 'A' + 10;
            res += (hex_digit) * (long)pow((double)16, (double)len - i - 1);
        }
        else
        {
            break;
        }
    }
    return res;
}
