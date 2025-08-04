#include <stdio.h>
void cyclic_sort(int arr[], int n)
{
    int i = 0;

    while (i < n)
    {
        int correct_index = arr[i] - 1;

        if (arr[i] != arr[correct_index])
        {
            int temp = arr[correct_index];
            arr[correct_index] = arr[i];
            arr[i] = temp;
        }
        else
        {
            i++;
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

    cyclic_sort(arr, n);

    printf("Sorted array : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
