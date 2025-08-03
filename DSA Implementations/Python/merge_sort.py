def merge(arr,low,mid,high):
    left = low
    right = mid+1
    temp = []
    
    while(left<=mid and right<=high):
        if arr[left]<=arr[right]:
            temp.append(arr[left])
            left+=1
        else:
            temp.append(arr[right])
            right+=1
    
    while(left<=mid):
        temp.append(arr[left])
        left+=1
    
    while(right<=high):
        temp.append(arr[right])
        right+=1
        
    for i in range(len(temp)):
        arr[low+i] = temp[i]

def merge_sort(arr,low,high):
    if(low>=high):
        return
    
    mid = (low+high)//2
    
    merge_sort(arr,low,mid)
    merge_sort(arr,mid+1,high)
    
    merge(arr,low,mid,high)

n = int(input("Enter the number of elements in the array : "))
arr = []

low = 0
high = n-1

print("Enter the elements of the array : ")
for _ in range(n):
    arr.append(int(input()))

merge_sort(arr,low,high)

print("Sorted array : ")
print(*arr)
