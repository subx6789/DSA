#include <iostream>
#include <vector>
using namespace std;

bool binary_search(const std::vector<std::vector<int>> &arr, int k)
{
    int rows = arr.size();
    if (rows == 0)
        return false;
    int cols = arr[0].size();
    if (cols == 0)
        return false;

    int left = 0;
    int right = (rows * cols) - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        int mid_row = mid / cols;
        int mid_col = mid % cols;

        if (arr[mid_row][mid_col] == k)
        {
            cout << "Element found at index (" << mid_row << ", " << mid_col << ")" << std::endl;
            return true;
        }
        else if (arr[mid_row][mid_col] < k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
}

int main()
{
    int rows, cols, k;

    cout << "Enter the number of rows in the matrix: ";
    cin >> rows;

    cout << "Enter the number of columns in the matrix: ";
    cin >> cols;

    vector<vector<int>> arr(rows, vector<int>(cols));

    cout << "Enter the elements of the matrix (Make sure it is sorted in ascending order): " << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Enter the element to be searched: ";
    cin >> k;

    bool is_found = binary_search(arr, k);

    if (!is_found)
    {
        cout << "Element not found in the matrix" << std::endl;
        return 1;
    }
    else
    {
        return 0;
    }
}