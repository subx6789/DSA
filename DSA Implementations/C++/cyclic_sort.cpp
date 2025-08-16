#include <iostream>
#include <vector>
#include <algorithm>

void cyclic_sort(std::vector<int> &arr)
{
    int i = 0;
    while (i < arr.size())
    {
        int correct_index = arr[i] - 1;
        if (arr[i] > 0 && arr[i] <= arr.size() && arr[i] != arr[correct_index])
        {
            std::swap(arr[i], arr[correct_index]);
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
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements of the array (numbers from 1 to " << n << "): " << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    cyclic_sort(arr);

    std::cout << "Sorted array: " << std::endl;
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}