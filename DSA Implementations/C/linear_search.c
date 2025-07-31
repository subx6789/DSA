#include <stdio.h>

int linear_search(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n, k;

    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array : \n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched : ");
    scanf("%d", &k);

    int linear_search_result = linear_search(arr, n, k);

    if (linear_search_result != -1)
    {
        printf("Element found at index %d\n", linear_search_result);
        return 0;
    }
    else
    {
        printf("Element not found in the array\n");
        return 1;
    }

    printf("Element not found in the array\n");
    return 0;
}