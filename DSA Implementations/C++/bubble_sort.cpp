#include <iostream>
#include <vector>
#include <algorithm>

void bubble_sort(std::vector<int> &arr)
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
                std::swap(arr[j], arr[j + 1]);
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

    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> arr(n);

    std::cout << "Enter the elements of the array: " << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    bubble_sort(arr);

    std::cout << "Sorted array: " << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}