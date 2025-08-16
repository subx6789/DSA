#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selection_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int min_index = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(arr[i], arr[min_index]);
        }
    }
}

int main()
{
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    selection_sort(arr);

    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}