#include <iostream>
#include <vector>
using namespace std;

bool linear_search(const vector<vector<int>> &arr, int k)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < arr[i].size(); ++j)
        {
            if (arr[i][j] == k)
            {
                cout << "Element found at index (" << i << ", " << j << ")" << endl;
                return true;
            }
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

    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Enter the element to be searched: ";
    cin >> k;

    bool is_found = linear_search(arr, k);

    if (!is_found)
    {
        cout << "Element not found in the matrix" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}