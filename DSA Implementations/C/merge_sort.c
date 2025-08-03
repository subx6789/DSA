#include <stdio.h>
void merge(int arr[], int low, int mid, int high)
{
    int left = low, right = mid + 1, k = 0;

    int temp[high - low + 1];

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[k++] = arr[left++];
        }
        else
        {
            temp[k++] = arr[right++];
        }
    }

    while (left <= mid)
    {
        temp[k++] = arr[left++];
    }

    while (right <= high)
    {
        temp[k++] = arr[right++];
    }

    for (int i = 0; i < k; i++)
    {
        arr[low + i] = temp[i];
    }
}

void merge_sort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;

    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

int main()
{
    int n, low, high;

    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array : \n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    low = 0;
    high = n - 1;

    merge_sort(arr, low, high);

    printf("Sorted array : \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}