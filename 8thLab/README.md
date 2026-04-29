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
