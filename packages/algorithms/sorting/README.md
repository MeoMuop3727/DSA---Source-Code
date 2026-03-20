# 🗂️ Sorting Algorithms

Sorting is the process of arranging elements in a dataset in a specific order (ascending or descending). It is one of the most essential operations in computer science, serving as a foundation for many other algorithms and widely used in databases, search engines, data analysis, and more.

---

## 📂 List of Algorithms

| # | Algorithm | Status |
|---|-----------|--------|
| 1 | [Interchange Sort](#1-interchange-sort) | ✅ |
| 2 | [Bubble Sort](#2-bubble-sort) | ✅ |
| 3 | [Selection Sort](#3-selection-sort) | ✅ |
| 4 | [Insertion Sort](#4-insertion-sort) | ✅ |
| 5 | [Merge Sort](#5-merge-sort) | ✅ |
| 6 | [Quick Sort](#6-quick-sort) | ✅ |
| 7 | [Heap Sort](#7-heap-sort) | ✅ |
| 8 | [Counting Sort](#8-counting-sort) | ✅ |
| 9 | [Bucket Sort](#9-bucket-sort) | ⬜ |
| 10 | [Radix Sort](#10-radix-sort) | ✅ |
| 11 | [Shell Sort](#11-shell-sort) | ✅ |

---

## 1. Interchange Sort

### Description
Compares every pair of elements in the array and swaps them if they are in the wrong order. Similar to Bubble Sort but without the early-termination optimization.

### When to use
- Simple educational purposes.
- Best for **very small** datasets where simplicity is preferred over performance.

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(n²) | O(n²) | O(n²) |
| **Space** | O(1) | O(1) | O(1) |

---

## 2. Bubble Sort

### Description
Repeatedly steps through the array, compares adjacent elements, and swaps them if they are in the wrong order. The largest unsorted element "bubbles up" to its correct position after each pass.

### When to use
- Simple educational purposes.
- Nearly sorted arrays where very few swaps are needed.

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(n) | O(n²) | O(n²) |
| **Space** | O(1) | O(1) | O(1) |

> 💡 Best case O(n) is achieved with an early-termination flag when no swaps occur in a pass.

---

## 3. Selection Sort

### Description
Divides the array into a sorted and unsorted region. On each pass, finds the **minimum element** from the unsorted region and places it at the beginning of that region.

### When to use
- When **minimizing the number of swaps** is important (e.g., memory with high write cost).
- Simple datasets where performance is not critical.

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(n²) | O(n²) | O(n²) |
| **Space** | O(1) | O(1) | O(1) |

---

## 4. Insertion Sort

### Description
Builds the sorted array one element at a time by picking each element and **inserting it into its correct position** among the already-sorted elements.

### When to use
- **Small or nearly sorted** datasets.
- Online sorting (data arriving one element at a time).
- Often used as a subroutine in hybrid algorithms (e.g., Timsort).

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(n) | O(n²) | O(n²) |
| **Space** | O(1) | O(1) | O(1) |

---

## 5. Merge Sort

### Description
A **divide and conquer** algorithm that recursively splits the array into halves, sorts each half, then **merges** them back together in sorted order.

### When to use
- **Large datasets** where stable sorting is required.
- Sorting **linked lists** (no random access needed).
- When guaranteed O(n log n) performance is needed.

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(n log n) | O(n log n) | O(n log n) |
| **Space** | O(n) | O(n) | O(n) |

---

## 6. Quick Sort

### Description
A **divide and conquer** algorithm that selects a **pivot** element and partitions the array into two sub-arrays — elements less than the pivot and elements greater than the pivot — then recursively sorts each sub-array.

### When to use
- **General-purpose sorting** — fastest in practice for most datasets.
- When average-case performance matters more than worst-case.

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(n log n) | O(n log n) | O(n²) |
| **Space** | O(log n) | O(log n) | O(n) |

> ⚠️ Worst case O(n²) occurs when the pivot is always the smallest or largest element (e.g., already sorted array with naive pivot selection).

---

## 7. Heap Sort

### Description
Builds a **max-heap** from the array, then repeatedly extracts the maximum element and places it at the end, reducing the heap size each time.

### When to use
- When **O(n log n) worst-case** is required with **O(1) space**.
- When memory usage is constrained.

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(n log n) | O(n log n) | O(n log n) |
| **Space** | O(1) | O(1) | O(1) |

---

## 8. Counting Sort

### Description
Counts the occurrences of each distinct element and uses those counts to place elements directly into their correct positions. Does **not use comparisons**.

### When to use
- Elements are **integers within a known, small range**.
- When linear time sorting is needed and range is not too large.

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(n + k) | O(n + k) | O(n + k) |
| **Space** | O(k) | O(k) | O(k) |

> where `k` is the range of input values.

---

## 9. Bucket Sort

### Description
Distributes elements into a number of **buckets**, sorts each bucket individually (usually with Insertion Sort), then concatenates them in order.

### When to use
- Input is **uniformly distributed** over a range.
- Floating-point numbers in a fixed range.

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(n + k) | O(n + k) | O(n²) |
| **Space** | O(n + k) | O(n + k) | O(n + k) |

> ⬜ **Not yet implemented** — will be updated later.

---

## 10. Radix Sort

### Description
Sorts integers by processing **individual digits** from the least significant to the most significant (LSD), using a stable sort (e.g., Counting Sort) at each digit level.

### When to use
- Sorting **integers or fixed-length strings**.
- When the number of digits `d` is small relative to `n`.

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(n · d) | O(n · d) | O(n · d) |
| **Space** | O(n + k) | O(n + k) | O(n + k) |

> where `d` is the number of digits and `k` is the base (e.g., 10 for decimal).

---

## 11. Shell Sort

### Description
An extension of Insertion Sort that allows the exchange of elements **far apart** from each other. Starts with a large gap between compared elements and progressively reduces the gap until it becomes 1.

### When to use
- **Medium-sized** datasets where Insertion Sort is too slow.
- When a simple in-place algorithm with better performance than O(n²) is needed.

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(n log n) | O(n log² n) | O(n log² n) |
| **Space** | O(1) | O(1) | O(1) |

> 💡 Performance depends heavily on the **gap sequence** chosen.

---

## 📊 Complexity Comparison

| Algorithm | Best | Average | Worst | Space | Stable? |
|-----------|------|---------|-------|-------|---------|
| Interchange Sort | O(n²) | O(n²) | O(n²) | O(1) | ❌ |
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | ✅ |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | ❌ |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | ✅ |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | ✅ |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | ❌ |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | ❌ |
| Counting Sort | O(n + k) | O(n + k) | O(n + k) | O(k) | ✅ |
| Bucket Sort | O(n + k) | O(n + k) | O(n²) | O(n + k) | ✅ |
| Radix Sort | O(n · d) | O(n · d) | O(n · d) | O(n + k) | ✅ |
| Shell Sort | O(n log n) | O(n log² n) | O(n log² n) | O(1) | ❌ |

> **Stable** means equal elements maintain their original relative order after sorting.

---

## 🧭 When to Use Which Algorithm?

| Situation | Recommended Algorithm |
|-----------|----------------------|
| Very small or nearly sorted array | Insertion Sort / Bubble Sort |
| General-purpose, fast in practice | Quick Sort |
| Guaranteed O(n log n), stable | Merge Sort |
| O(n log n) with O(1) space | Heap Sort |
| Integer keys in a small range | Counting Sort |
| Uniformly distributed floats | Bucket Sort |
| Fixed-length integers or strings | Radix Sort |
| Minimize number of writes/swaps | Selection Sort |
| Medium-sized, simple in-place | Shell Sort |

---

## 📁 Folder Structure

```
sorting/
├── README.md
├── InterchangeSort.cpp
├── BubbleSort.cpp
├── SelectionSort.cpp
├── InsertionSort.cpp
├── MergeSort.cpp
├── QuickSort.cpp
├── HeapSort.cpp
├── CountingSort.cpp
├── BucketSort.cpp
├── RadixSort.cpp
└── ShellSort.cpp
```