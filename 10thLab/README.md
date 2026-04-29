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
