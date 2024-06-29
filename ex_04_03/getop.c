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
    else if (c == '-')
    {
        // check whether the next character is digit or .
        if ((c = getch()) == '.' || isdigit(c))
        {
            i = 0;
            s[++i] = c;
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
        else
        {
            // It is not. Return the read character. And return '-'
            ungetch(c);
            return '-';
        }
    }
    else
    {
        i = 0;
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
}
