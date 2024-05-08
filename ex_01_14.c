#include <stdio.h>
#define n_char 128

void print_horizontal_histogram(int stat[], int star_size);

int main()
{
    int c;
    int stat[n_char] = {0};

    while ((c = getchar()) != EOF)
    {
        stat[c]++;
    }
    print_horizontal_histogram(stat, 2000);

    return 0;
}

void print_horizontal_histogram(int stat[], int star_size)
{

    printf("Horizontal Histogram\n");
    for (int i = 0; i < n_char; i++)
    {
        if (stat[i] != 0)
        {

            putchar(i);
            printf(": ");
            for (int foo = stat[i]; foo > 0; foo -= star_size)
            {
                printf("*");
            }
            printf("\n");
        }
    }
}
