#include <iostream>
#include <vector>

int binary_search(const std::vector<int> &arr, int k)
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

    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> arr(n);

    std::cout << "Enter the elements of the array (Make sure it is sorted in ascending order): " << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    std::cout << "Enter the element to be searched: ";
    std::cin >> k;

    int binary_search_result = binary_search(arr, k);

    if (binary_search_result != -1)
    {
        std::cout << "Element found at index " << binary_search_result << std::endl;
        return 0;
    }
    else
    {
        std::cout << "Element not found in the array" << std::endl;
        return 1;
    }
}