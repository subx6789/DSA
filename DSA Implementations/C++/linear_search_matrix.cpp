#include <iostream>
#include <vector>

bool linear_search(const std::vector<std::vector<int>> &arr, int k)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < arr[i].size(); ++j)
        {
            if (arr[i][j] == k)
            {
                std::cout << "Element found at index (" << i << ", " << j << ")" << std::endl;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int rows, cols, k;

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

    std::cout << "Enter the element to be searched: ";
    std::cin >> k;

    bool is_found = linear_search(arr, k);

    if (!is_found)
    {
        std::cout << "Element not found in the matrix" << std::endl;
        return 1;
    }
    else
    {
        return 0;
    }
}