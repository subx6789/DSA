#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sort_matrix(vector<vector<int>> &arr)
{
    if (arr.empty() || arr[0].empty())
    {
        return;
    }

    int rows = arr.size();
    int cols = arr[0].size();

    vector<int> temp_vec;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            temp_vec.push_back(arr[i][j]);
        }
    }

    sort(temp_vec.begin(), temp_vec.end());

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

    sort_matrix(arr);

    cout << "Sorted matrix: " << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}