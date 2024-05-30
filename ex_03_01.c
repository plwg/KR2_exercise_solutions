#include <stdio.h>
#include <time.h>

#define MAX_NUM 20000

int binsearch_1(int x, int v[], int n);
int binsearch_2(int x, int v[], int n);

int main()
{
    int arr[MAX_NUM];
    clock_t timer;
    int index;

    for (int i = 0; i < MAX_NUM; i++)
    {
        arr[i] = i;
    }

    timer = clock();
    for (int i = 0; i < 100000; i++)
    {
        index = binsearch_1(-1, arr, MAX_NUM);
    }
    timer = clock() - timer;
    printf("Clock ticks: %lu\n", (unsigned long)timer);

    timer = clock();
    for (int i = 0; i < 100000; i++)
    {
        index = binsearch_2(-1, arr, MAX_NUM);
    }
    timer = clock() - timer;
    printf("Clock ticks: %lu\n", (unsigned long)timer);
    return 0;
}

// Original version
int binsearch_1(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

// New version
int binsearch_2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (v[mid] != x && low <= high)
    {
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    if (v[mid] == x)
    {
        return mid;
    }
    else
    {
        return -1;
    }
}
