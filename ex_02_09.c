#include "print_binary.h"
#include <stdio.h>

unsigned bitcount(unsigned x);

int main()
{
    unsigned x = 1211;

    print_binary(x);

    printf("%u", bitcount(x));

    return 0;
}

unsigned bitcount(unsigned x)
{
    int i;

    for(i = 0; x != 0; i++)
    {
        x &= (x - 1);
    }
    return i;
}