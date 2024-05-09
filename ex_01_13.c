#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void print_horizontal_histogram(int stat[], int len, int star_size);
void print_vertical_histogram(int stat[], int len, int height, int star_size);
int calc_star_size(int max, int max_dim);

int main()
{

    const int MAX_DIM = 20;
    const int NBIN = 20;

    int c;
    int stat[NBIN];
    bool is_in_word = false;
    int count, max;
    int bin;
    int height;

    count = max = 0;

    for (int i = 0; i < NBIN; i++)
    {
        stat[i] = 0;
    }

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
        max = (stat[i] > max ? stat[i] : max);
    }

    height = max > MAX_DIM ? MAX_DIM : max;

    print_horizontal_histogram(stat, NBIN, calc_star_size(max, MAX_DIM));
    printf("\n\n\n\n\n");
    print_vertical_histogram(stat, NBIN, height, calc_star_size(max, height));

    return 0;
}
int calc_star_size(int max, int max_dim)
{
    return max < max_dim ? 1 : max / max_dim + 1;
}

void print_horizontal_histogram(int stat[], int len, int star_size)
{

    printf("Horizontal Histogram\n");
    for (int i = 0; i < len; i++)
    {
        if (i < len - 1)
        {
            printf("%10d: ", i + 1);
        }
        else
        {
            printf("%d and %d+: ", len, len);
        }
        for (int foo = stat[i]; foo > 0; foo -= star_size)
        {
            printf("*");
        }
        printf("\n");
    }
}

void print_vertical_histogram(int stat[], int len, int height, int star_size)
{
    printf("Vertical Histogram\n");
    for (int i = height - 1; i >= 1; i--)
    {
        printf("|");
        for (int j = 0; j < len; j++)
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
    for (int j = 0; j < len; j++)
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
    printf(" ");
    for (int j = 0; j < len; j++)
    {
        printf("%2d ", j + 1);
    }
    printf("\n");
}