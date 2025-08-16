#include <iostream>
#include <vector>
using namespace std;

int binary_search(const vector<int> &arr, int k)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] < k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, k;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array (Make sure it is sorted in ascending order): " << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << "Enter the element to be searched: ";
    cin >> k;

    int binary_search_result = binary_search(arr, k);

    if (binary_search_result != -1)
    {
        cout << "Element found at index " << binary_search_result << endl;
        return 0;
    }
    else
    {
        cout << "Element not found in the array" << endl;
        return 1;
    }
}