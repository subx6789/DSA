#include <iostream>
#include <vector>
#include <algorithm>

void sort_matrix(std::vector<std::vector<int>> &arr)
{
    if (arr.empty() || arr[0].empty())
    {
        return;
    }

    int rows = arr.size();
    int cols = arr[0].size();

    std::vector<int> temp_vec;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            temp_vec.push_back(arr[i][j]);
        }
    }

    std::sort(temp_vec.begin(), temp_vec.end());

    int k = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            arr[i][j] = temp_vec[k++];
        }
    }
}

int main()
{
    int rows, cols;

    std::cout << "Enter the number of rows in the matrix: ";
    std::cin >> rows;

    std::cout << "Enter the number of columns in the matrix: ";
    std::cin >> cols;

    std::vector<std::vector<int>> arr(rows, std::vector<int>(cols));

    std::cout << "Enter the elements of the matrix: " << std::endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cin >> arr[i][j];
        }
    }

    sort_matrix(arr);

    std::cout << "Sorted matrix: " << std::endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}