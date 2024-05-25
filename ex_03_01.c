#include <stdio.h>

int binsearch(int x, int v[], int n);
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};

    printf("%d\n", binsearch(7, arr, 8));
    printf("%d\n", binsearch(6, arr, 8));

    return 0;
}

int binsearch(int x, int v[], int n)
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