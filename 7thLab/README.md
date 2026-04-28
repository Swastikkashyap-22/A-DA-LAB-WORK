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
