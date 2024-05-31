#include "reverse.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int min_field_width);
void reverse(char s[]);

int main()
{
    char test[100];
    int test_num = INT_MIN;

    itoa(test_num, test, 32);

    printf("%d\n", test_num);
    printf("%s\n", test);

    return 0;
}

void itoa(int n, char s[], int min_field_width)
{
    int i, sign, is_min;

    is_min = (n == INT_MIN);

    if ((sign = n) < 0)
    {
        if (is_min)
        {
            n = -(n + 1);
        }
        else
        {
            n = -n;
        }
    }
    i = 0;
    do
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
    {
        s[i++] = '-';
    }

    while (i < min_field_width)
    {
        s[i++] = ' ';
    }

    s[i] = '\0';

    if (is_min)
    {
        s[0] = s[0] + 1;
    }
    reverse(s);
}
