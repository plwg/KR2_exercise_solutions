#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itob(int n, char s[], int b);

int main()
{
    char a[100];
    char b[100];
    char c[100];
    int n = 19940723;
    itob(n, a, 2);
    itob(n, b, 8);
    itob(n, c, 16);
    printf("Original number: %32d\n", n);
    printf("         Base 2: %32s\n", a);
    printf("        Base  8: %32s\n", b);
    printf("        Base 16: %32s\n", c);
}

void itob(int n, char s[], int b)
{
    char set[] = "0123456789ABCDEF";
    int i = 0;
    int neg = 0;

    if (n < 0)
    {
        n *= -1;
        neg = 1;
    }

    while (n > 0)
    {
        s[i] = set[n % b];
        n /= b;
        i++;
    }

    if (neg)
    {
        s[i++] = '-';
    }

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
