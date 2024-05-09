#include <stdio.h>

int calc_star_size(int max, int max_dim);
void print_horizontal_histogram(int stat[], int len, int star_size);

int main()
{
    const int N_CHAR = 128;
    const int DIM = 20;
    int c;
    int max = 0;
    int stat[N_CHAR];

    for (int i = 0; i < N_CHAR; i++)
    {
        stat[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        stat[c]++;
    }

    for (int i = 0; i < N_CHAR; i++)
    {
        max = stat[i] > max ? stat[i] : max;
    }

    print_horizontal_histogram(stat, N_CHAR, calc_star_size(max, DIM));

    return 0;
}

int calc_star_size(int max, int max_dim)
{
    return max < max_dim ? 1 : max / max_dim + 1;
}

void print_horizontal_histogram(int stat[], int len, int star_size)
{
    for (int i = 0; i < len; i++)
    {
        if (stat[i] != 0)
        {

            putchar(i);
            printf(": ");
            do
            {
                printf("*");
                stat[i] -= star_size;
            } while (stat[i] > 0);

            printf("\n");
        }
    }
}
