#include <iostream>
#include <vector>

int linear_search(const std::vector<int> &arr, int k)
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

    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> arr(n);

    std::cout << "Enter the elements of the array: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << "Enter the element to be searched: ";
    std::cin >> k;

    int linear_search_result = linear_search(arr, k);

    if (linear_search_result != -1)
    {
        std::cout << "Element found at index " << linear_search_result << std::endl;
        return 0;
    }
    else
    {
        std::cout << "Element not found in the array" << std::endl;
        return 1;
    }
}