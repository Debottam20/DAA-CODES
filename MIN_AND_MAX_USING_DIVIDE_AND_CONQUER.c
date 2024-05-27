
#include <stdio.h>
int max, min, arr[100];
void maxmin(int lo, int hi)
{
    int max1, min1, mid;
    if (lo == hi)
    {
        max = min = arr[lo];
    }
    else
    {
        if (lo == hi - 1)
        {
            if (arr[lo] < arr[hi])
            {
                max = arr[hi];
                min = arr[lo];
            }
            else
            {
                max = arr[lo];
                min = arr[hi];
            }
        }
        else
        {
            mid = (lo + hi) / 2;
            maxmin(lo, mid);
            max1 = max;
            min1 = min;
            maxmin(mid + 1, hi);
            if (max < max1)
            {
                max = max1;
            }
            if (min > min1)
            {
                min = min1;
            }
        }
    }
}
int main()
{
    int size, i;
    printf("Enter the size:\n");
    scanf("%d", &size);
    printf("Enter the elemrnts :\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    max = arr[0];
    min = arr[0];
    maxmin(0, size - 1);
    printf("Minimum element in an array : %d\n", min);
    printf("Maximum element in an array : %d\n", max);
    return 0;
}