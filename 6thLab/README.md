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
