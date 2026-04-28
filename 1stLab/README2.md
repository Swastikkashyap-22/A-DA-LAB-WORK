# 📘 1st Lab - C++ Algorithms Repository

---

## 🔹 1.cpp: Power of a Number

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

( O(\log n) )

---

## 🔹 2.cpp: Tower of Hanoi

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

## 🔹 3.cpp: Number of Bounces of a Ball

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

## 🔹 4.cpp: Permutation Generator

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

## 🔹 5.cpp: Horner's Law

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

## 🔹 6.cpp: Earliest Duplicate

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

## 🔹 7.cpp: Missing Consecutive Number

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

## 🔹 8.cpp: Selection Sort (Recursive)

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

## 🔹 9.cpp: Bubble Sort (Recursive)

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

## 🔹 10.cpp: Linear Search (Recursive)

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
