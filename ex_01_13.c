#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define NBIN 20
#define MAX_DIM 20

void print_horizontal_histogram(int stat[], int star_size);
void print_vertical_histogram(int stat[], int height, int star_size);

int main()
{
    int c;
    int stat[NBIN] = {0};
    bool is_in_word = false;
    int count, max;
    int bin;
    int height;

    count = max = 0;

    while ((c = getchar()) != EOF)
    {
        if (isspace(c) || ispunct(c) || isdigit(c))
        {
            if (is_in_word == true)
            {
                bin = count;

                if (bin > NBIN)
                {
                    bin = NBIN;
                }

                stat[bin - 1]++;
            }
            count = 0;
            is_in_word = false;
        }
        else
        {
            is_in_word = true;
            count++;
        }
    }

    for (int i = 0; i < NBIN; i++)
    {
        if (stat[i] > max)
        {
            max = stat[i];
        }
    }

    height = max > MAX_DIM ? MAX_DIM : max;

    print_horizontal_histogram(stat, max / MAX_DIM + 1);
    printf("\n\n\n\n\n");
    print_vertical_histogram(stat, height, max / height + 1);

    return 0;
}

void print_horizontal_histogram(int stat[], int star_size)
{

    printf("Horizontal Histogram\n");
    for (int i = 0; i < NBIN; i++)
    {
        if (i < NBIN - 1)
        {
            printf("%10d: ", i + 1);
        }
        else
        {
            printf("%d and %d+: ", NBIN, NBIN);
        }
        for (int foo = stat[i]; foo > 0; foo -= star_size)
        {
            printf("*");
        }
        printf("\n");
    }
}

void print_vertical_histogram(int stat[], int height, int star_size)
{
    printf("Vertical Histogram\n");
    for (int i = height - 1; i >= 1; i--)
    {
        printf("|");
        for (int j = 0; j < NBIN; j++)
        {
            if (stat[j] >= (i * star_size))
            {
                printf(" *|");
            }
            else
            {
                printf("  |");
            }
        }
        printf("\n");
    }
    printf("|");
    for (int j = 0; j < NBIN; j++)
    {
        if (stat[j] > 0)
        {
            printf(" *|");
        }
        else
        {
            printf("  |");
        }
    }
    printf("\n");
    printf(" "); // Align the labels with the bars
    for (int j = 0; j < NBIN; j++)
    {
        printf("%2d ", j + 1);
    }
    printf("\n");
}