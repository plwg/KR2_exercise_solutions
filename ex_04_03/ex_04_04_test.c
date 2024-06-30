#include "calc.h"
#include <stdio.h>

int main()
{
    push(1);
    push(2);
    push(3);
    printf("------------\n");
    print_stack();
    printf("------------\n");
    print_top();
    printf("------------\n");
    print_stack();
    printf("------------\n");
    duplicate_top();
    print_stack();
    printf("------------\n");
    push(4);
    print_stack();
    printf("------------\n");
    swap_top_two();
    print_stack();
    printf("------------\n");
    clear_stack();
    print_stack();
    printf("------------\n");
    print_top();
    return 0;
}
