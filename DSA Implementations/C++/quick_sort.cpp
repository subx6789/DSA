#include <iostream>
#include <vector>
#include <algorithm>

int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low)
        {
            j--;
        }
        if (i < j)
        {
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[low], arr[j]);
    return j;
}

void quick_sort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int p_index = partition(arr, low, high);
        quick_sort(arr, low, p_index - 1);
        quick_sort(arr, p_index + 1, high);
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

    quick_sort(arr, 0, n - 1);

    std::cout << "Sorted array: " << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}