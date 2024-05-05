/*
1. Tested zero lenght input
2. Tested moby dick
*/
#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

/* counts lines, words and characters as input */

int main()
{
    unsigned int current, state;

    state = OUT;

    while ((current = getchar()) != EOF)
    {
        if (current == ' ' || current == '\n' || current == '\t')
        {
            if (state == IN) 
            {
                printf("\n");
            }

            state = OUT;
        }
        else
        {
           state = IN;
           putchar(current);
        }
    }

    return 0;
}