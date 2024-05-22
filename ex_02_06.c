#include <stdio.h>
#include <stdlib.h>

void printBinary(unsigned);
unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y);

int main()
{
    unsigned x = 4095;
    unsigned y = 42;

    setbits(x, 6, 5, y);

    return 0;
}

void printBinary(unsigned n)
{
    int bits = sizeof(n) * 8;

    for (int i = bits - 1; i >= 0; i--)
    {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
    unsigned mask = ~((~0) << n);
    unsigned right_most_n = mask & y;
    int shift_left = p - n + 1;

    if (shift_left < 0)
    {
        printf("Position specified not left enough to accomodate bits.");
        printf("Returning original bits.");
        return x;

    }
    else if (p > (8 * sizeof(unsigned) - 1) || n > (8 * sizeof(unsigned)))
    {
        printf("Position exceeding length.");
        printf("Returning original bits.");
        return x;
    }
    else
    {
        printf("%35s", "X: ");
        printBinary(x);

        printf("%35s", "Y: ");
        printBinary(y);

        printf("%35s", "MASK: ");
        printBinary(mask);

        printf("%35s", "RIGHT MOST N OF Y: ");
        printBinary(right_most_n);

        printf("%35s", "RIGHT MOST N OF Y SHIFTED LEFT: ");
        printBinary(right_most_n << shift_left);

        printf("%35s", "X WITH HOLE: ");
        unsigned x_with_hole = ~(mask << shift_left) & x;
        printBinary(x_with_hole);

        printf("%35s", "RESULT: ");
        unsigned res = x_with_hole | (right_most_n << shift_left);
        printBinary(res);

        return res;
    }
}