# A-DA-LAB-WORK

# 1st Lab

---

## 1.cpp: Power of a Number

### Aim

To find the value of ( x ) raised to power ( n ).

### Use Cases

* Cryptographic algorithms (like RSA) which rely heavily on modular exponentiation.
* Calculating geometric progressions and series.
* Scientific simulations requiring fast exponential growth calculations.

### Variables Used

* **x**: Base integer
* **n**: Exponent integer
* **m**: A temporary copy of the exponent used for iteration
* **z**: A temporary copy of the base used for multiplication
* **Pow**: Accumulator for the final result
* **start, stop, duration**: Variables to measure execution time

### Algorithm

```
function Power(x, n):
    m = n
    z = x
    Pow = 1
    while m > 0:
        while m % 2 == 0:
            m = m / 2
            z = z * z
        m = m - 1
        Pow = Pow * z
    return Pow
```

### Time Complexity

( O(log n) )

---

## 2.cpp: Tower of Hanoi

### Aim

To solve the classic Tower of Hanoi mathematical puzzle using recursion.

### Use Cases

* Teaching algorithm design and recursive problem-solving.
* Performance benchmarking of recursive limits in programming languages.
* Base logic for solving mechanical and sequential logic puzzles.

### Variables Used

* **n**: Number of discs
* **F**: Source/From peg character representation
* **U**: Auxiliary/Using peg character representation
* **T**: Destination/To peg character representation
* **start, stop, duration**: Variables to measure execution time

### Algorithm

```
function TOH(n, F, U, T):
    if n == 1:
        print "Move disc from", F, "->", T
    else:
        TOH(n - 1, F, T, U)
        print "Move disc from", F, "->", T
        TOH(n - 1, U, F, T)
```

### Time Complexity

( O(2^n) )

---

## 3.cpp: Number of Bounces of a Ball

### Aim

To find the number of times a ball bounces given an initial velocity and a constant velocity decay factor.

### Use Cases

* Simulating basic rigid-body physics in game development.
* Calculating collision and kinetic energy decay in physics engines.

### Variables Used

* **v, vel**: The current/initial velocity of the ball
* **n**: An integer counter tracking the number of bounces
* **start, stop, duration**: Variables to measure execution time

### Algorithm

```
function Tips(v, n):
    if v <= 1:
        return n
    else:
        return Tips(0.575 * v, n + 1)
```

### Time Complexity

( O(\log v) )

---

## 4.cpp: Permutation Generator

### Aim

To generate and print all possible permutations of a given string.

### Use Cases

* Generating brute-force dictionaries for penetration testing.
* Solving anagram puzzles or combinatorial scheduling algorithms.
* Generating test cases containing all possible orderings of elements.

### Variables Used

* **input**: The string whose permutations are being found
* **first**: Starting index of the current recursive step
* **last**: Ending index of the current recursive step
* **i**: Loop counter for swapping characters
* **num**: Size of the string
* **start, stop, duration**: Variables to measure execution time

### Algorithm

```
function P(input, first, last):
    if first == last:
        print input
    else:
        for i from first to last:
            swap(input[i], input[first])
            P(input, first + 1, last)
            swap(input[i], input[first])  // Backtrack
```

### Time Complexity

( O(n \times n!) )

---

## 5.cpp: Horner's Law

### Aim

To evaluate a polynomial effectively by minimizing the number of multiplications using Horner's method (recursive approach).

### Use Cases

* Fast calculation of polynomial series in computational mathematics.
* Converting numbers from one radix/base to another.
* Efficient mathematical implementations inside graphing calculators.

### Variables Used

* **arr**: Array storing the polynomial coefficients
* **idx**: The current array index being processed
* **m**: Maximum index (size - 1)
* **x**: The variable value to substitute into the polynomial
* **n**: The number of elements (degree of polynomial + 1)
* Random generation utilities (rd, gen, valueDist)

### Algorithm

```
function solveHorner(arr, idx, m, x):
    if idx == m + 1:
        return 0
    return arr[idx] + x * solveHorner(arr, idx + 1, m, x)
```

### Time Complexity

( O(n) )

---

## 6.cpp: Earliest Duplicate

### Aim

To find the index of the earliest duplicate element in an array based on a nested traversal.

### Use Cases

* Validating input data to catch repetitive entries early in a stream.
* Abstract syntax tree verifications in basic compilers.

### Variables Used

* **arr**: The array of integers
* **size**: Total number of elements in the array
* **uppermid**: Tracking index starting dynamically from the array's midpoint
* **i, j**: Iterators for nested loops

### Algorithm

```
function earliestDuplicate(arr, size):
    uppermid = (size + 1) / 2
    for i from uppermid - 1 down to 0:
        for j from i - 1 down to 0:
            if arr[i] == arr[j]:
                uppermid = i
    return uppermid
```

### Time Complexity

( O(n^2) )

---

## 7.cpp: Missing Consecutive Number

### Aim

To find the missing number in a consecutive series using the XOR bitwise operator.

### Use Cases

* Network protocol data integrity (identifying lost sequence packets).
* High-performance verification checks in consecutive database primary keys.
* O(1) space complexity algorithms for sequence gap finding.

### Variables Used

* **lowerLimit**: Start of the consecutive range
* **upperLimit**: End of the consecutive range
* **consec**: The array containing the sequence with one missing element
* **size**: Number of elements in the given sequence
* **ans**: Variable holding the cumulative XOR results

### Algorithm

```
function findMissing(lowerLimit, upperLimit, consec, size):
    ans = 0
    for i from 0 to size - 1:
        ans = ans XOR consec[i]
    for i from lowerLimit to upperLimit:
        ans = ans XOR i
    return ans
```

### Time Complexity

( O(n) )

---

## 8.cpp: Selection Sort (Recursive)

### Aim

To implement Selection Sort recursively to sort an array.

### Use Cases

* Situations where memory write operations (swaps) are highly expensive (like EEPROM).
* Sorting small internal lists where simple logic overhead is preferred.

### Variables Used

* **A**: Target array to be sorted
* **n**: Total elements in the array
* **i**: Current starting boundary of the unsorted segment
* **sIndex**: Position of the smallest element found
* **j**: Iterator looking for the smallest element

### Algorithm

```
function selSort(A, n, i):
    if i == n - 1:
        return
    sIndex = i
    for j from i + 1 to n - 1:
        if A[j] < A[sIndex]:
            sIndex = j
    swap(A[i], A[sIndex])
    selSort(A, n, i + 1)
```

### Time Complexity

( O(n^2) )

---

## 9.cpp: Bubble Sort (Recursive)

### Aim

To implement Bubble Sort recursively to sort an array.

### Use Cases

* Educational tool for explaining sorting visualizations.
* Useful as a fallback algorithm to check if an array is already sorted (if early exit flags are implemented).

### Variables Used

* **A**: The array being sorted
* **n**: Total elements currently being considered in the iteration block
* **j**: Iterator responsible for comparing adjacent pairs

### Algorithm

```
function bubSort(A, n):
    if n == 1:
        return
    for j from 0 to n - 2:
        if A[j] > A[j+1]:
            swap(A[j], A[j+1])
    bubSort(A, n - 1)
```

### Time Complexity

( O(n^2) )

---

## 10.cpp: Linear Search (Recursive)

### Aim

To implement Linear Search recursively to find an element within an array.

### Use Cases

* Finding an item in small or unsorted data structures where the overhead of maintaining sorted bounds for Binary Search isn't justified.
* Linked list traversals where random access isn't possible.

### Variables Used

* **a**: Target array to search within
* **n**: Total size of the array
* **element**: The target data value we are looking for
* **i**: Current search index

### Algorithm

```
function LSearch(a, n, element, i):
    if i == n:
        print "Element not found!"
        return
    else if a[i] == element:
        print "Element found at index", i + 1
        return
    else:
        LSearch(a, n, element, i + 1)
```

### Time Complexity

( O(n) )

---

---

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

---

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

---

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

* Best Case: ( O(nlog n) )
* Average Case: ( O(nlog n) )
* Worst Case: ( O(n^2) )

---

## 2.cpp: Binary Search

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
* Average Case: ( O(log n) )
* Worst Case: ( O(log n) )

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

---

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

---

# 6th Lab

---

## 1.cpp: Dijkstra (Single Source Shortest Path)

### Aim

To find the shortest path from a single source vertex to all other vertices using Dijkstra’s algorithm.

### Use Cases

* Network routing protocols (shortest path computation).
* GPS and navigation systems.
* Graph-based optimization problems.

### Variables Used

* **cost**: Adjacency matrix representing graph weights
* **n**: Number of vertices
* **v (source)**: Source vertex
* **visited**: Array to track visited vertices
* **dist**: Array storing shortest distances
* **i, j, u, w**: Loop and helper variables
* **min**: Minimum distance value during selection
* **INF**: Constant representing infinity
* **start, stop, duration**: Variables to measure execution time

### Algorithm

```
function Dijkstra(cost, n, source):
    initialize visited[] and dist[]
    mark source as visited
    for each vertex:
        select unvisited vertex with minimum distance
        mark it visited
        update distances of adjacent vertices
```

### Time Complexity

( O(n^2) )

---

## 2.cpp: Activity Selection Problem

### Aim

To select the maximum number of non-overlapping activities using greedy strategies.

### Use Cases

* Scheduling problems (CPU scheduling, event planning).
* Resource allocation in time-based systems.
* Optimization problems involving intervals.

### Variables Used

* **id**: Array representing activity identifiers
* **start**: Array storing start times
* **finish**: Array storing finish times
* **tid, tstart, tfinish**: Temporary arrays for processing
* **n**: Number of activities
* **mode**: Strategy selector (finish time or duration)
* **last**: Index of last selected activity
* **count**: Total number of selected activities
* **start_time, end_time, duration**: Variables to measure execution time

### Algorithm

```
function pickActivities(id, start, finish, n, mode):
    copy arrays into temporary arrays
    sort activities based on selected strategy
    select first activity
    for each remaining activity:
        if start time >= finish time of last selected:
            select activity
```

### Time Complexity

( O(n^2) ) (due to sorting)

---

## 3.cpp: Prim’s Algorithm

### Aim

To find the Minimum Spanning Tree (MST) of a graph using Prim’s algorithm.

### Use Cases

* Network design (minimum cost wiring).
* Road and communication network optimization.
* Graph-based clustering problems.

### Variables Used

* **graph / cost**: Adjacency matrix representing graph
* **V**: Number of vertices
* **near**: Array storing nearest vertex information
* **mst**: Matrix storing MST edges
* **u, v, k**: Vertices used during selection
* **minEdge, smallest**: Minimum edge values
* **totalCost**: Total weight of MST
* **INF**: Constant representing infinity
* **start, end, duration**: Variables to measure execution time

### Algorithm

```
function primMST(cost):
    find minimum edge and initialize MST
    initialize near array
    for remaining vertices:
        select minimum edge connecting MST
        add edge to MST
        update near array
```

### Time Complexity

( O(V^2) )

---

## 4.cpp: Cycle Detection (Undirected Graph)

### Aim

To detect the presence of a cycle in an undirected graph using Depth First Search (DFS).

### Use Cases

* Detecting loops in network topology.
* Graph validation in compilers and data structures.
* Identifying redundant connections in systems.

### Variables Used

* **graph**: Adjacency list representation of graph
* **vertices (n)**: Number of vertices
* **visited**: Array to track visited nodes
* **current**: Current node in DFS traversal
* **prev**: Parent node to avoid false cycle detection
* **adjNode**: Adjacent node during traversal

### Algorithm

```
function checkCycle(vertices, graph):
    initialize visited array
    for each vertex:
        if not visited:
            if DFS detects cycle:
                return true
    return false

function DFS(current, prev):
    mark current as visited
    for each adjacent node:
        if not visited:
            recursively call DFS
        else if node is not parent:
            cycle detected
```

### Time Complexity

( O(V + E) )

---

---

# 7th Lab
---

## 1.cpp: Finding Stages in a Multistage Graph

### Aim

To determine the stage number of each vertex in a multistage graph using a breadth-first traversal approach.

### Use Cases

* Multistage graph problems in dynamic programming.
* Layered network analysis (e.g., pipeline stages, workflows).
* Determining levels in directed acyclic graphs (DAGs).

### Variables Used

* **n**: Number of vertices
* **e**: Number of edges
* **cost**: Adjacency matrix representing graph weights
* **INF**: Constant representing absence of edge
* **stage / stages**: Vectors storing vertices belonging to each stage
* **vertex_stage**: Array storing stage number of each vertex
* **q**: Queue used for breadth-first traversal
* **u, v**: Variables representing current and adjacent vertices
* **max_stage**: Maximum stage number identified
* **start, end, duration**: Variables to measure execution time

### Algorithm

```
function findStages(cost, n):
    initialize vertex_stage array to -1
    push source vertex into queue
    assign stage 0 to source

    while queue not empty:
        u = dequeue
        for each vertex v:
            if edge exists and v not assigned:
                assign stage of v = stage[u] + 1
                enqueue v

    find maximum stage value
    group vertices based on their stage numbers
```

### Time Complexity

( O(n^2) )

---

---

# 8th Lab

---

## 1.cpp: Matrix Chain Multiplication

### Aim

To determine the minimum number of scalar multiplications required to multiply a chain of matrices using dynamic programming.

### Use Cases

* Optimizing matrix computations in scientific computing.
* Compiler optimization for evaluating expressions.
* Reducing computational cost in linear algebra operations.

### Variables Used

* **dimMatrix**: Array storing dimensions of matrices
* **n**: Size of dimension array
* **len**: Number of matrices (n - 1)
* **memo**: DP table storing minimum multiplication costs
* **s**: Table storing split positions for optimal solution
* **i, j, k**: Indices used for subproblem computation
* **l**: Chain length
* **q**: Temporary cost for a given split

### Algorithm

```
function matrixChainMultiplication(dimMatrix, n):
    initialize memo[i][i] = 0
    for chain length l from 2 to n-1:
        for each i:
            j = i + l - 1
            memo[i][j] = INF
            for k from i to j-1:
                cost = memo[i][k] + memo[k+1][j] 
                       + dimMatrix[i] * dimMatrix[k+1] * dimMatrix[j+1]
                update minimum cost
    return memo[0][n-2]
```

### Time Complexity

( O(n^3) )

---

## 2.cpp: Multistage Graph Shortest Path (MSG)

### Aim

To find the shortest path from source to destination in a multistage graph using recursion with memoization.

### Use Cases

* Stage-wise decision problems in dynamic programming.
* Network routing in layered architectures.
* Optimization in directed acyclic graphs (DAGs).

### Variables Used

* **graph**: Adjacency matrix representing the graph
* **cost**: Array storing minimum cost from each node to destination
* **nextNode**: Array storing next node in optimal path
* **n**: Number of vertices
* **u, v**: Current and adjacent vertices
* **temp**: Temporary cost for comparison
* **INF**: Constant representing infinity
* **start, end, duration**: Variables to measure execution time

### Algorithm

```
function computePath(u):
    if u is destination:
        return 0
    if cost[u] already computed:
        return cost[u]

    set cost[u] = INF
    for each vertex v > u:
        if edge exists:
            temp = weight(u,v) + computePath(v)
            update minimum cost and nextNode

    return cost[u]

function printPath():
    start from source
    follow nextNode until destination
```

### Time Complexity

( O(n^2) )

---

---

# 9th Lab

---

## 1.cpp: 0/1 Knapsack

### Aim

To determine the maximum value that can be obtained within a given weight capacity using dynamic programming.

### Use Cases

* Resource allocation with indivisible items.
* Budget optimization problems.
* Decision-making in constrained environments.

### Variables Used

* **W**: Maximum weight capacity
* **wt**: Array storing weights of items
* **val**: Array storing values of items
* **n**: Number of items
* **v**: DP table storing maximum value for subproblems
* **i, j**: Indices for iteration
* **start, stop, duration**: Variables to measure execution time

### Algorithm

```
function knapsack(W, wt, val, n):
    initialize DP table v
    for i from 0 to n:
        for j from 0 to W:
            if i == 0 or j == 0:
                v[i][j] = 0
            else if wt[i-1] <= j:
                v[i][j] = max(val[i-1] + v[i-1][j-wt[i-1]], v[i-1][j])
            else:
                v[i][j] = v[i-1][j]
    return v[n][W]
```

### Time Complexity

( O(n * W) )

---

## 2.cpp: Floyd Warshall (All-Pairs Shortest Path)

### Aim

To compute the shortest paths between all pairs of vertices in a graph.

### Use Cases

* Network routing between all nodes.
* Graph analysis in dense networks.
* Transitive closure and path optimization.

### Variables Used

* **adjacency_matrix**: Input graph representation
* **result**: Matrix storing shortest path distances
* **current_distance**: Intermediate distance matrix
* **n**: Number of vertices
* **i, j, k**: Loop variables for iteration
* **INT_MAX**: Constant for infinity
* **start, stop, duration**: Variables to measure execution time

### Algorithm

```
function FloydWarshall(matrix, n):
    initialize distance matrix
    for each intermediate vertex i:
        for each pair (j, k):
            if path through i is shorter:
                update distance[j][k]
    return result matrix
```

### Time Complexity

( O(n^3) )

---

## 3.cpp: LCS (Longest Common Subsequence)

### Aim

To find the longest common subsequence between two strings using dynamic programming.

### Use Cases

* Text comparison and diff tools.
* DNA sequence analysis.
* Version control systems.

### Variables Used

* **text1, text2**: Input strings
* **memo**: DP array storing LCS lengths
* **cols**: Number of columns for 2D indexing
* **i, j**: Indices for iteration
* **lcs**: String storing resulting subsequence

### Algorithm

```
function solve(text1, text2):
    initialize DP table
    for i from 1 to n:
        for j from 1 to m:
            if characters match:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    return dp[n][m]

function getLCS():
    trace back from dp[n][m] to reconstruct sequence
```

### Time Complexity

( O(n * m) )

---

## 4.cpp: N-Queens Problem

### Aim

To place N queens on an N×N chessboard such that no two queens attack each other.

### Use Cases

* Constraint satisfaction problems.
* Backtracking algorithm demonstrations.
* Puzzle and game development.

### Variables Used

* **n**: Size of chessboard / number of queens
* **pos**: Array storing column positions of queens
* **queenNum**: Current queen being placed
* **i, j**: Loop variables
* **queenY**: Column position of previous queens

### Algorithm

```
function place(queenNum):
    if all queens placed:
        return true
    for each column:
        check for conflicts
        if safe:
            place queen
            recursively place next queen
    return false
```

### Time Complexity

( O(n!) )

---

## 5.cpp: Travelling Sales Person (TSP)

### Aim

To find the minimum cost of visiting all vertices exactly once and returning to the starting point using dynamic programming with bit masking.

### Use Cases

* Route optimization (logistics, delivery systems).
* Circuit design and path planning.
* Optimization in transportation problems.

### Variables Used

* **adj**: Adjacency matrix representing graph
* **n**: Number of vertices
* **memo**: DP array storing computed states
* **vertex**: Current vertex
* **mask**: Bitmask representing visited vertices
* **completedVisit**: Bitmask indicating all vertices visited
* **i**: Loop variable
* **index**: Computed index for memoization

### Algorithm

```
function travelRec(vertex, mask):
    if all vertices visited:
        return cost to return to start
    if state already computed:
        return memo value
    for each unvisited vertex:
        compute cost recursively
        update minimum
    store result in memo
    return minimum cost
```

### Time Complexity

( O(n^2 * 2^n) )

---

---

# 10th Lab 

---

## **1. Subset Sum Problem**

### **Aim**

To find all subsets of a given set whose sum equals a specified target value.

### **Use Cases**

* Solving combinatorial problems in optimization.
* Resource allocation where combinations must meet constraints.
* Cryptography (subset-based problems).
* Decision-making problems involving selections under constraints.

### **Variables Used**

* `arr[]` – Input array.
* `n` – Number of elements.
* `target` – Required sum.
* `temp[]` – Stores current subset.
* `len` – Current subset size.
* `sum` – Current sum.
* `pos` – Current index.
* `count` – Number of valid subsets.

### **Algorithm (Pseudocode)**

```
FUNCTION GenerateSubsets(arr, n, target, pos, sum, temp, len, count)

    IF sum == target THEN
        PRINT temp[0 to len-1]
        count ← count + 1
    ENDIF

    IF pos == n OR sum > target THEN
        RETURN
    ENDIF

    // Include current element
    temp[len] ← arr[pos]
    GenerateSubsets(arr, n, target, pos+1, sum + arr[pos], temp, len+1, count)

    // Exclude current element
    GenerateSubsets(arr, n, target, pos+1, sum, temp, len, count)

END FUNCTION
```

### **Time Complexity**

* Worst Case: **O(2ⁿ)**

---

## **2. Graph Coloring Problem**

### **Aim**

To determine the minimum number of colors required to color a graph such that no two adjacent vertices share the same color.

### **Use Cases**

* Scheduling problems (exam timetables, task scheduling).
* Register allocation in compilers.
* Map coloring.
* Frequency assignment in networks.

### **Variables Used**

* `n` – Number of vertices.
* `m` – Number of colors.
* `G[][]` – Adjacency matrix.
* `col[]` – Color assigned to each vertex.

### **Algorithm (Pseudocode)**

```
FUNCTION IsValid(node, color)
    FOR i ← 0 TO n-1
        IF G[node][i] == 1 AND col[i] == color THEN
            RETURN FALSE
        ENDIF
    END FOR
    RETURN TRUE
END FUNCTION


FUNCTION AssignColor(node)
    IF node == n THEN
        RETURN TRUE
    ENDIF

    FOR c ← 1 TO m
        IF IsValid(node, c) THEN
            col[node] ← c

            IF AssignColor(node + 1) == TRUE THEN
                RETURN TRUE
            ENDIF

            col[node] ← 0
        ENDIF
    END FOR

    RETURN FALSE
END FUNCTION


MAIN:
    m ← 1
    WHILE TRUE
        RESET col[]
        IF AssignColor(0) == TRUE THEN
            PRINT m
            BREAK
        ENDIF
        m ← m + 1
    END WHILE
```

### **Time Complexity**

* Worst Case: **O(mⁿ)**

---

## **3. Hamiltonian Cycle**

### **Aim**

To determine whether a Hamiltonian cycle exists in a graph and display it if present.

### **Use Cases**

* Route planning and circuit design.
* Graph traversal problems.
* Network optimization.
* Logistics and pathfinding.

### **Variables Used**

* `n` – Number of vertices.
* `adj[][]` – Adjacency matrix.
* `cycle[]` – Stores cycle path.
* `step` – Current position in cycle.

### **Algorithm (Pseudocode)**

```
FUNCTION CanPlace(node, step)
    IF adj[cycle[step-1]][node] == 0 THEN
        RETURN FALSE
    ENDIF

    FOR i ← 0 TO step-1
        IF cycle[i] == node THEN
            RETURN FALSE
        ENDIF
    END FOR

    RETURN TRUE
END FUNCTION


FUNCTION BuildCycle(step)
    IF step == n THEN
        IF adj[cycle[step-1]][cycle[0]] == 1 THEN
            cycle[step] ← cycle[0]
            RETURN TRUE
        ELSE
            RETURN FALSE
        ENDIF
    ENDIF

    FOR candidate ← 1 TO n-1
        IF CanPlace(candidate, step) THEN
            cycle[step] ← candidate

            IF BuildCycle(step + 1) == TRUE THEN
                RETURN TRUE
            ENDIF

            cycle[step] ← -1
        ENDIF
    END FOR

    RETURN FALSE
END FUNCTION


MAIN:
    cycle[0] ← 0
    IF BuildCycle(1) == TRUE THEN
        PRINT cycle
    ELSE
        PRINT "No cycle exists"
    ENDIF
```

### **Time Complexity**

* Worst Case: **O(n!)**

---
