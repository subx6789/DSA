def insertion_sort(arr,n):
    for i in range(n):
        j = i
        while j>0 and arr[j-1]>arr[j]:
            temp=arr[j-1]
            arr[j-1]=arr[j]
            arr[j]=temp
            j-=1

n = int(input("Enter the number of elements in the array : "))
arr = []

print("Enter the elements of the array : ")
for _ in range(n):
    arr.append(int(input()))

insertion_sort(arr,n)

print("Sorted array : ")
print(*arr)
