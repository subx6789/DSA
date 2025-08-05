#include <stdio.h>
void sort_matrix(int row, int col, int arr[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int k = 0; k < row; k++)
            {
                for (int l = 0; l < col; l++)
                {
                    if (arr[k][l] > arr[i][j])
                    {
                        int temp = arr[i][j];
                        arr[i][j] = arr[k][l];
                        arr[k][l] = temp;
                    }
                }
            }
        }
    }
}

int main()
{
    int row, col;

    printf("Enter the number of rows in the array : ");
    scanf("%d", &row);

    printf("Enter the number of rows in the array : ");
    scanf("%d", &col);

    int arr[row][col];

    printf("Enter the elements of the array : \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    sort_matrix(row, col, arr);

    printf("Sorted array : \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
