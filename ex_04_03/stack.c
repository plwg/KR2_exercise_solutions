#include <stdio.h>
#define MAXVAL 100
#include "calc.h"

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void print_top(void)
{
    if (sp > 0)
    {
        printf("%f\n", val[sp - 1]);
    }
    else
    {
        printf("stack is empty.\n");
    }
}

void duplicate_top(void)
{
    if (sp > 0 && sp < MAXVAL)
    {
        double top = val[sp - 1];
        val[sp] = top;
        sp++;
    }
    else if (sp == 0)
    {
        printf("error: stack is empty, can't duplicate top\n");
    }
    else
    {
        printf("error: stack full, can't duplicate top\n");
    }
}

void swap_top_two(void)
{
    if (sp > 1)
    {
        double temp;

        temp = val[sp - 2];
        val[sp - 2] = val[sp - 1];
        val[sp - 1] = temp;
    }
    else
    {
        printf("error: at least need two elements in stack for swapping.\n");
    }
}

void clear_stack(void)
{
    sp = 0;
}

void print_stack(void)
{
    if (sp > 0)
    {
        for (int i = sp - 1; i >= 0; i--)
        {
            printf("%f\n", val[i]);
        }
    }
    else
    {
        printf("stack is empty.\n");
    }
}
