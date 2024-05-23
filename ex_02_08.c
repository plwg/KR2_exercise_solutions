#include "print_binary.h"
#include <stdio.h>

unsigned rightrot(unsigned x, unsigned n);

int main()
{
    unsigned x = (~0 << 3);

    rightrot(x, 40);

    return 0;
}

unsigned rightrot(unsigned x, unsigned n)
{
    int size_n = sizeof(n) * 8;
    n %= size_n;
    unsigned mask = ~((~0) << n);
    unsigned res;

    printf("%30s", "X: ");
    print_binary(x);

    printf("%30s", "MASK: ");
    print_binary(mask);

    printf("%30s", "MASKED X: ");
    print_binary(mask & x);

    printf("%30s", "MASKED X SHIFTED RIGHT: ");
    print_binary((mask & x) << (size_n - n));

    printf("%30s", "RESULT: ");
    print_binary(res = (((mask & x) << (size_n - n)) | (x >> n)));

    return res;
}