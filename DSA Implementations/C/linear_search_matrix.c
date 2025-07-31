#include <stdio.h>
int linear_search(int rows, int cols, int arr[rows][cols], int k)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == k)
            {
                printf("Element found at index (%d, %d)\n", i, j);
                return 1;
            }
        }
    }
    return -1;
}

int main()
{
    int rows, cols, k;

    printf("Enter the number of rows in the matrix : ");
    scanf("%d", &rows);

    printf("Enter the number of columns in the matrix : ");
    scanf("%d", &cols);

    int arr[rows][cols];

    printf("Enter the elements of the matrix : \n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter the element to be searched : ");
    scanf("%d", &k);

    int linear_search_result = linear_search(rows, cols, arr, k);

    if (linear_search_result == -1)
    {
        printf("Element not found in the matrix\n");
        return 1;
    }
    else
    {
        return 0;
    }
}