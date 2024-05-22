#include "print_binary.h"
#include <stdio.h>
#include <stdlib.h>

unsigned invert(unsigned x, unsigned p, unsigned n);

int main()
{
    unsigned x = 43812;
    unsigned y = 42;

    invert(x, 6, 5);

    return 0;
}

unsigned invert(unsigned x, unsigned p, unsigned n)
{
    int shift_left = p - n + 1;
    if (shift_left < 0)
    {
        printf("Position specified not left enough to accomodate bits.\n");
        printf("Returning original bits.");
        return x;
    }
    else if (p > (8 * sizeof(unsigned) - 1) || n > (8 * sizeof(unsigned)))
    {
        printf("Position exceeding length.\n");
        printf("Returning original bits.");
        return x;
    }
    else
    {
        unsigned patch_mask = ~((~0) << n) << (p - n + 1);
        unsigned hole_mask = ~patch_mask;
        unsigned res;

        printf("%25s", "X: ");
        print_binary(x);

        printf("%25s", "HOLE MASK: ");
        print_binary(hole_mask);

        printf("%25s", "PATCH MASK: ");
        print_binary(patch_mask);

        printf("%25s", "X WITH HOLE: ");
        print_binary(x & hole_mask);

        printf("%25s", "X PATCH: ");
        print_binary(x & patch_mask);

        printf("%25s", "Flip X PATCH: ");
        print_binary(~(x & patch_mask) & patch_mask);

        printf("%25s", "Result: ");
        print_binary((res = (~(x & patch_mask) & patch_mask) | (x & hole_mask)));

        return res;
    }
}