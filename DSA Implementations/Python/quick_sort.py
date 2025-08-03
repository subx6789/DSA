def pivot_index(arr, low, high):
    
    pivot = arr[low]
    i = low
    j= high
    
    while i < j:
        
        while i <= high and arr[i] <= pivot:
            i += 1
        
        while j >= low and arr[j] > pivot:
            j -= 1
        
        if i < j:
            arr[i], arr[j] = arr[j], arr[i]
    
    arr[low], arr[j] = arr[j], arr[low]
    
    return j

def quick_sort(arr, low, high):
    if low < high:
        pIndex = pivot_index(arr, low, high)
        quick_sort(arr, low, pIndex-1)
        quick_sort(arr, pIndex+1, high)

n = int(input("Enter the number of elements in the array : "))
arr = []

low = 0
high = n-1

print("Enter the elements of the array : ")
for _ in range(n):
    arr.append(int(input()))

quick_sort(arr, low, high)

print("Sorted array : ")
print(*arr)
