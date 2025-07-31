#include <stdio.h>

int binary_search(int rows, int cols, int arr[rows][cols], int k)
{
    int lb = 0, ub = (rows * cols) - 1, mid = 0;
    while (lb <= ub)
    {
        mid = (lb + ub) / 2;

        int mid_row = mid / cols;
        int mid_col = mid % cols;

        if (arr[mid_row][mid_col] == k)
        {
            printf("Element found at index (%d, %d)\n", mid_row, mid_col);
            return 1;
        }
        else if (arr[mid_row][mid_col] < k)
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
    int rows, cols, k;

    printf("Enter the number of rows in the matrix : ");
    scanf("%d", &rows);

    printf("Enter the number of columns in the matrix : ");
    scanf("%d", &cols);

    int arr[rows][cols];

    printf("Enter the elements of the matrix (Make sure it is sorted in ascending order) : \n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter the element to be searched : ");
    scanf("%d", &k);

    int binary_search_result = binary_search(rows, cols, arr, k);

    if (binary_search_result == -1)
    {
        printf("Element not found in the matrix\n");
        return 1;
    }
    else
    {
        return 0;
    }
}