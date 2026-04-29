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
