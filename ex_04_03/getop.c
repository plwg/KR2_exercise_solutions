#include "calc.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int getop(char s[])
{
    int i, c;
    int math_func;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
    {
        ;
    }
    s[1] = '\0';
    
    if ((math_func = get_math_function(c)) != 0)
    {
        return math_func;
    }

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
            // If it is not, unread the read character and return '-'
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


// edge case kljdfsajfa;ls
int get_math_function(int first)
{
    char name[6];
    int c;
    int i = 0;
    
    ungetch(first);

    while(i < 5 && (c = getch()) != ' ' && c != '\n' && c != EOF)
    {
        name[i++] = c; 
    } 

    name[i] = '\0';
    if (strcmp(name,"sin") == 0)
    {
        ungetch(c);
        return SIN;
    }
    else if (strcmp(name,"pow") == 0)
    {
        ungetch(c);
        return POW;
    }
    else if (strcmp(name,"exp") == 0)
    {
        ungetch(c);
        return EXP;
    }
    else
    {
        ungetch(c);
        for (int j=0; name[j] != '\0'; j++)
        {
            ungetch(name[j]);
        }
        getch();
        return 0;
    }
}
