#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertion_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        int current = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
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

    insertion_sort(arr);

    cout << "Sorted array: " << endl;
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}