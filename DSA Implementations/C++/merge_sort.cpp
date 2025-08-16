#include <iostream>
#include <vector>

void merge(std::vector<int> &arr, int low, int mid, int high)
{
    int left = low, right = mid + 1;
    std::vector<int> temp;
    temp.reserve(high - low + 1);

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }

    while (right <= high)
    {
        temp.push_back(arr[right++]);
    }

    for (size_t i = 0; i < temp.size(); ++i)
    {
        arr[low + i] = temp[i];
    }
}

void merge_sort(std::vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = low + (high - low) / 2;

    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
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

    merge_sort(arr, 0, n - 1);

    std::cout << "Sorted array: " << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}