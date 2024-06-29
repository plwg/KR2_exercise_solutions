#include "calc.h"
#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
    {
        ;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c;
    }
    i = 0;
    if (c == '-')
    {
        c = getch();
        // check whether the next character is digit or .
        if (isdigit(c))
        {
            ungetch(c);
        }
        else if (c == '.')
        {
            s[++i] = '.';
        }
        else
        {
            // It is not. Return the read character. And return '-'
            ungetch(c);
            return '-';
        }
    }
    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
    }
    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }
    return NUMBER;
}
