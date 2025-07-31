#include <stdio.h>
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    int n;

    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubble_sort(arr, n);

    printf("Sorted array : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
