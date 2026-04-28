# 5th Lab

---

## 1.cpp: Knapsack Problem (Fractional)

### Aim

To solve the Fractional Knapsack problem using different greedy strategies.

### Use Cases

* Resource allocation problems where items can be divided.
* Optimization in logistics and finance.
* Decision-making systems using greedy strategies.

### Variables Used

* **items**: Matrix storing weight, profit, and profit/weight ratio
* **case1, case2, case3**: Copies of items for different sorting strategies
* **n**: Number of items
* **capacity (cap)**: Maximum capacity of knapsack
* **total**: Total profit accumulated
* **wdist, pdist**: Random distributions for weight and profit generation
* **gen, rd**: Random number generators
* **p1, p2, p3**: Profits obtained using different strategies

### Algorithm

```
function fractionalKnapsack(items, capacity):
    sort items based on strategy
    total = 0
    for each item:
        if capacity >= weight:
            take full item
            capacity -= weight
            total += profit
        else:
            take fraction
            total += ratio * capacity
            break
    return total
```

### Time Complexity

( O(n^2) ) (due to sorting using nested loops)

---

## 2.cpp: Convex Hull

### Aim

To compute the convex hull of a set of points using a divide-and-conquer approach (QuickHull).

### Use Cases

* Computational geometry problems.
* Collision detection in computer graphics.
* GIS and spatial data analysis.

### Variables Used

* **Point**: Class representing a 2D point (x, y)
* **points**: Input set of points
* **hull**: Stores convex hull points
* **A, B, P**: Points used during hull construction
* **leftSet1, leftSet2**: Subsets of points for recursive processing
* **minIdx, maxIdx**: Indices of extreme points
* **upper, lower**: Partitioned sets of points
* **start, stop, duration**: Variables to measure execution time

### Algorithm

```
function computeHull(points):
    find leftmost and rightmost points
    divide points into upper and lower sets
    recursively find farthest point from line
    split into subsets and repeat
    add points to hull
```

### Time Complexity

* Average Case: ( O(n \log n) )
* Worst Case: ( O(n^2) )

---

## 3.cpp: k-th Smallest Element

### Aim

To find the k-th smallest element in an array using a partition-based selection algorithm.

### Use Cases

* Order statistics problems.
* Finding median or percentile values.
* Efficient selection in large datasets.

### Variables Used

* **arr**: Input array
* **left, right**: Bounds of the array/sub-array
* **k**: Desired position (k-th smallest element)
* **pivot**: Pivot element for partitioning
* **i, j**: Indices used during partitioning
* **pos**: Final position of pivot after partition
* **start, end, duration**: Variables to measure execution time

### Algorithm

```
function kthSmallest(arr, left, right, k):
    pos = partition(arr, left, right)
    if pos == k - 1:
        return arr[pos]
    else if pos > k - 1:
        return kthSmallest(arr, left, pos - 1, k)
    else:
        return kthSmallest(arr, pos + 1, right, k)
```

### Time Complexity

* Best Case: ( O(n) )
* Average Case: ( O(n) )
* Worst Case: ( O(n^2) )

---
