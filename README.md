# UCS415 – Design and Analysis of Algorithms (DAA)
## Lab Assignment 1 (Week 2 & 3) — Divide and Conquer

This repository contains C++ implementations of core **Divide and Conquer algorithms** as part of **UCS415 – Design and Analysis of Algorithms** lab work.

---

## Topics Covered
- Binary Search
- Merge Sort
- Quick Sort
- Maximum Subarray Sum (Divide & Conquer)
- Additional advanced problems (from competitive programming)

---

## Questions Implemented

### Part A — Core Divide & Conquer
| Q.No | Problem | File Name |
|------|---------|----------|
| 1 | Binary Search (Target = 23) | `Q1.cpp` |
| 2 | Merge Sort (Two arrays) | `Q2.cpp` |
| 3 | Quick Sort | `Q3.cpp` |
| 4 | Maximum Subarray Sum | `Q4.cpp` |

---

### Part B (Additional Questions)

| AQ.No | Problem Statement (Short) | File Name |
|------|----------------------------|----------|
| AQ1 | Divide array into ≤ M segments to minimize the maximum Bitwise OR | `AQ1.cpp` |
| AQ2 | Maximum length of a good subsequence (abs diff ≤ 10 for all pairs) | `AQ2.cpp` |
| AQ3 | Median-removal process repeated N-2 times, output sum of remaining elements | `AQ3.cpp` |
| AQ4 | Find specialty sum using the “special element” definition with exactly k greater elements | `AQ4.cpp` |
| AQ5 | Minimum size of square to fit N rectangles (no rotation allowed) | `AQ5.cpp` |
| AQ6 | Closest pair of points in 2D plane using Divide & Conquer | `AQ6.cpp` |

---

## Core Techniques Used

### AQ1: Minimize Maximum OR
- Binary Search on Answer  
- Greedy segmentation check

### AQ2: Longest Good Subsequence
- Frequency counting  
- Sliding window over values

### AQ3: Median Removal Game
- Mathematical observation based approach  
- Sorting / greedy logic

### AQ4: Specialty of Sequence
- Brute force solution version (for smaller constraints)
- (Can be optimized with Fenwick Tree / Coordinate Compression for large constraints)

### AQ5: Minimum Square Side
- Binary Search on Answer  
- Fit check using grid formula:
  - ⌊S/W⌋ × ⌊S/H⌋ ≥ N

### AQ6: Closest Pair of Points
- Divide and Conquer
- Strip checking after recursion

---
