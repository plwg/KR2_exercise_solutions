#include <stdio.h>

int main()
{
    // ex_01_02.c: In function ‘main’:
    // ex_01_02.c:5:12: warning: unknown escape sequence: '\z'
    //     5 |     printf("hello, world\z\n");
    //       |            ^~~~~~~~~~~~~~~~~~
    printf("hello, world\z\n");
    return 0;
}
