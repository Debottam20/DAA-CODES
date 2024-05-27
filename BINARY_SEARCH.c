#include <stdio.h>
int BinarySearch(int arr[], int size_of_array, int element)
{
    int low, mid, high;
    low = 0;
    high = (size_of_array)-1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}
int main()
{
    int size, temp, num, i, j, search_index;
    printf("Enter the size of the array :\n");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array :\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Before sorting the array is :\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    // Bubble sort starts from here
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nAfter sorting the array is :\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nEnter the number you want to search :\n");
    scanf("%d", &num);
    search_index = BinarySearch(arr, size, num);
    if (search_index >= 0)
    {
        printf("The number %d was found at index %d of the array", num, search_index);
    }
    else
    {
        printf("The number %d was not present in the array", num);
    }

    return 0;
}