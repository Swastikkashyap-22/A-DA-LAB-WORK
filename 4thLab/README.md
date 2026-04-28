# 4th Lab

---

## 1.cpp: Iterative Quick Sort (Smaller Partition First)

### Aim

To implement Quick Sort iteratively using an explicit stack and optimizing by solving the smaller partition first.

### Use Cases

* Eliminating recursion overhead in environments with limited stack memory.
* Optimized quick sort implementations in systems programming.
* Handling large datasets without risk of stack overflow.

### Variables Used

* **arr**: Array to be sorted
* **n**: Total number of elements
* **l, h**: Lower and higher bounds of current sub-array
* **lstack, hstack**: Arrays used to simulate recursion stack
* **top**: Pointer to the top of the stack
* **i, j**: Indices used during partitioning
* **pivot**: Pivot element for partitioning
* **t**: Temporary variable used for swapping
* **start, stop, duration**: Variables to measure execution time

### Algorithm

```
function quickSort(arr, n):
    initialize stacks
    push initial range (0, n-1)

    while stack not empty:
        pop l, h
        while l < h:
            partition array using pivot
            if left partition smaller:
                push right partition
                process left
            else:
                push left partition
                process right
```

### Time Complexity

* Best Case: ( O(n \log n) )
* Average Case: ( O(n \log n) )
* Worst Case: ( O(n^2) )

---

## 2.cpp: Binary Sort (Ternary Search)

### Aim

To implement a search algorithm by dividing the array into three parts (n/3 and 2n/3).

### Use Cases

* Searching in sorted datasets with alternative divide strategies.
* Educational comparison with binary search.
* Demonstrating multi-way divide-and-conquer techniques.

### Variables Used

* **arr**: Sorted array
* **n**: Total number of elements
* **target**: Element to be searched
* **low, high**: Search boundaries
* **mid1, mid2**: Division points of the array
* **result**: Index where target is found
* **start, stop, duration**: Variables to measure execution time

### Algorithm

```
function binSearch(arr, n, target):
    low = 0, high = n - 1
    while low <= high:
        mid1 = low + (high - low) / 3
        mid2 = high - (high - low) / 3

        if arr[mid1] == target:
            return mid1
        if arr[mid2] == target:
            return mid2

        if target < arr[mid1]:
            high = mid1 - 1
        else if target > arr[mid2]:
            low = mid2 + 1
        else:
            low = mid1 + 1
            high = mid2 - 1
    return -1
```

### Time Complexity

* Best Case: ( O(1) )
* Average Case: ( O(\log n) )
* Worst Case: ( O(\log n) )

---

## 3.cpp: Permutation Generator

### Aim

To generate and print all possible permutations of a given string.

### Use Cases

* Generating all possible arrangements of characters.
* Solving combinatorial problems and anagrams.
* Used in brute-force search and testing scenarios.

### Variables Used

* **str**: Input string
* **left**: Starting index for permutation
* **right**: Ending index for permutation
* **i**: Loop counter for swapping
* **temp**: Temporary variable used in swapping
* **start, end, duration_ms**: Variables to measure execution time

### Algorithm

```
function permute(str, left, right):
    if left == right:
        print str
    else:
        for i from left to right:
            swap(str[left], str[i])
            permute(str, left + 1, right)
            swap(str[left], str[i])
```

### Time Complexity

( O(n * n!) )

---

* Execution time measured using `<chrono>`.
