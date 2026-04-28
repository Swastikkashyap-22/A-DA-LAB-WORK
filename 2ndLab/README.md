# 2nd Lab 

---

## 1.cpp: Insertion Sort

### Aim

To implement the Insertion Sort algorithm to sort an array.

### Use Cases

* Efficient for small datasets or nearly sorted arrays.
* Used in hybrid sorting algorithms like TimSort.
* Suitable for online sorting where elements are received one at a time.

### Variables Used

* **arr**: Array to be sorted
* **n**: Total number of elements in the array
* **i**: Loop variable for traversal starting from second element
* **curr**: Current element to be placed correctly
* **prev**: Index used to compare and shift elements
* **start, stop, duration**: Variables to measure execution time

### Algorithm

```
function insertionSort(arr, n):
    for i from 1 to n - 1:
        curr = arr[i]
        prev = i - 1
        while prev >= 0 and arr[prev] > curr:
            arr[prev + 1] = arr[prev]
            prev = prev - 1
        arr[prev + 1] = curr
```

### Time Complexity

* Best Case: ( O(n) )
* Average Case: ( O(n^2) )
* Worst Case: ( O(n^2) )

---

## 2.cpp: Binary Search

### Aim

To implement Binary Search recursively to find an element in a sorted array.

### Use Cases

* Fast searching in large sorted datasets.
* Used in database indexing and lookup operations.
* Core algorithm in divide-and-conquer strategies.

### Variables Used

* **arr**: Sorted array in which search is performed
* **target**: Element to be searched
* **start**: Starting index of search range
* **end**: Ending index of search range
* **mid**: Middle index used to divide the search space
* **result**: Stores the index where target is found
* **start, stop, duration**: Variables to measure execution time

### Algorithm

```
function binSearch(arr, target, start, end):
    if start > end:
        return -1
    mid = (end - start)/2 + start
    if arr[mid] == target:
        return mid
    else if arr[mid] < target:
        return binSearch(arr, target, mid + 1, end)
    else:
        return binSearch(arr, target, start, mid - 1)
```

### Time Complexity

* Best Case: ( O(1) )
* Average Case: ( O(log n) )
* Worst Case: ( O(log n) )

---
