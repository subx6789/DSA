#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubble_sort(vector<int> &arr)
{
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
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

    bubble_sort(arr);

    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}