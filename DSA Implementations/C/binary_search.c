#include <stdio.h>

int binary_search(int arr[], int n, int k)
{
    int lb = 0, ub = n - 1, mid = 0;
    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] < k)
        {
            lb = mid + 1;
        }
        else
        {
            ub = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, k, arr[100];

    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);

    printf("Enter the elements of the array (Make sure it is sorted in ascending order) : \n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched : ");
    scanf("%d", &k);

    int binary_search_result = binary_search(arr, n, k);

    if (binary_search_result != -1)
    {
        printf("Element found at index %d\n", binary_search_result);
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