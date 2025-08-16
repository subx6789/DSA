#include <iostream>
#include <vector>
using namespace std;

int linear_search(const vector<int> &arr, int k)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == k)
        {
            return i;
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

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the element to be searched: ";
    cin >> k;

    int linear_search_result = linear_search(arr, k);

    if (linear_search_result != -1)
    {
        cout << "Element found at index " << linear_search_result << endl;
        return 0;
    }
    else
    {
        cout << "Element not found in the array" << endl;
        return 1;
    }
}