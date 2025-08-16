#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void cyclic_sort(vector<int> &arr)
{
    int i = 0;
    while (i < arr.size())
    {
        int correct_index = arr[i] - 1;
        if (arr[i] > 0 && arr[i] <= arr.size() && arr[i] != arr[correct_index])
        {
            swap(arr[i], arr[correct_index]);
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array (numbers from 1 to " << n << "): " << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cyclic_sort(arr);

    cout << "Sorted array: " << endl;
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}