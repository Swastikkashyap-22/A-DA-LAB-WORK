# 3rd Lab

---

## 1.cpp: Quick Sort

### Aim

To implement the Quick Sort algorithm using partitioning.

### Use Cases

* Efficient sorting for large datasets.
* Used in systems where in-place sorting is preferred.
* Widely applied in standard library implementations (like `qsort`).

### Variables Used

* **arr**: Array to be sorted
* **start**: Starting index of the array/sub-array
* **end**: Ending index of the array/sub-array
* **pivot**: Element chosen as pivot for partitioning
* **i, j**: Indices used for partitioning and swapping
* **pivotIdx**: Final position of the pivot after partitioning
* **start, stop, duration**: Variables to measure execution time

### Algorithm

```
function quickSort(arr, start, end):
    if start >= end:
        return
    pivotIdx = partition(arr, start, end)
    quickSort(arr, start, pivotIdx - 1)
    quickSort(arr, pivotIdx + 1, end)

function partition(arr, start, end):
    pivot = arr[start]
    i = start + 1
    j = end
    while i <= j:
        while i <= end and arr[i] <= pivot:
            i = i + 1
        while arr[j] > pivot:
            j = j - 1
        if i < j:
            swap(arr[i], arr[j])
    swap(arr[start], arr[j])
    return j
```

### Time Complexity

* Best Case: ( O(nlog n) )
* Average Case: ( O(nlog n) )
* Worst Case: ( O(n^2) )

---

## 2.cpp: Merge Sort

### Aim

To implement the Merge Sort algorithm using an iterative (bottom-up) approach.

### Use Cases

* Stable sorting where relative order must be preserved.
* External sorting (large datasets stored in files).
* Efficient sorting for linked lists and large-scale data processing.

### Variables Used

* **arr**: Array to be sorted
* **n**: Total number of elements
* **left**: Starting index of sub-array
* **mid**: Middle index dividing sub-arrays
* **right**: Ending index of sub-array
* **i, j, k**: Indices used during merging process
* **temp**: Temporary array used for merging
* **size**: Current size of sub-arrays being merged
* **start, stop, duration**: Variables to measure execution time

### Algorithm

```
function mergeSort(arr, n):
    create temp array of size n
    for size from 1 while size < n:
        for left from 0 to n - size step 2*size:
            mid = left + size - 1
            right = min(left + 2*size - 1, n - 1)
            merge(arr, left, mid, right, temp)

function merge(arr, left, mid, right, temp):
    i = left
    j = mid + 1
    k = left

    while i <= mid and j <= right:
        if arr[i] < arr[j]:
            temp[k++] = arr[i++]
        else:
            temp[k++] = arr[j++]

    while i <= mid:
        temp[k++] = arr[i++]

    while j <= right:
        temp[k++] = arr[j++]

    copy temp[left...right] back to arr
```

### Time Complexity

* Best Case: ( O(nlog n) )
* Average Case: ( O(nlog n) )
* Worst Case: ( O(nlog n) )

---

<img width="975" height="214" alt="image" src="https://github.com/user-attachments/assets/ac2a9d00-3bda-41ea-930b-edda164e9760" />

---
