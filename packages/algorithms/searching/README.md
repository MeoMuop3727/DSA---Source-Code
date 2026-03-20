# 🔍 Searching Algorithms

Searching is the process of locating a specific element within a dataset. It is one of the most fundamental operations in computer science, widely used in databases, artificial intelligence, text processing, and many other fields.

---

## 📂 List of Algorithms

| # | Algorithm | Status |
|---|-----------|--------|
| 1 | [Linear Search](#1-linear-search) | ✅ |
| 2 | [Binary Search](#2-binary-search) | ✅ |
| 3 | [Ternary Search](#3-ternary-search) | ✅ |
| 4 | [Jump Search](#4-jump-search) | ✅ |
| 5 | [Exponential Search](#5-exponential-search) | ✅ |
| 6 | [Hashing Search](#6-hashing-search) | ⬜ |
| 7 | [Interpolation Search](#7-interpolation-search) | ✅ |
| 8 | [Fibonacci Search](#8-fibonacci-search) | ✅ |

---

## 1. Linear Search

### Description
Sequentially traverses each element in the array from start to end until the target element is found or the entire array has been scanned.

### When to use
- The array does **not need to be sorted**.
- Best suited for **small** datasets or one-time searches.

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(1) | O(n) | O(n) |
| **Space** | O(1) | O(1) | O(1) |

---

## 2. Binary Search

### Description
At each step, divides the search range in half by comparing the middle element with the target. Searches the right half if the target is larger, or the left half if smaller.

### When to use
- The array **must be sorted**.
- Efficient for **large** datasets.

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(1) | O(log n) | O(log n) |
| **Space** | O(1) | O(1) | O(1) |

---

## 3. Ternary Search

### Description
Similar to Binary Search but divides the array into **3 parts** instead of 2, using two midpoints `mid1` and `mid2` to determine the next search range.

### When to use
- The array **must be sorted**.
- Commonly used to find the **extremum of a unimodal function** (mathematics / optimization).

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(1) | O(log₃ n) | O(log₃ n) |
| **Space** | O(1) | O(1) | O(1) |

> ⚠️ In practice, Ternary Search is **not faster** than Binary Search because it requires more comparisons per iteration even though it has fewer iterations.

---

## 4. Jump Search

### Description
Instead of checking every element, the algorithm **jumps** ahead by fixed steps of size `√n`, then performs a linear search within the identified block.

### When to use
- The array **must be sorted**.
- More efficient than Linear Search and simpler than Binary Search for moderately large datasets.

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(1) | O(√n) | O(√n) |
| **Space** | O(1) | O(1) | O(1) |

---

## 5. Exponential Search

### Description
Finds the range containing the target by doubling the index exponentially (1, 2, 4, 8, ...), then applies **Binary Search** within that range.

### When to use
- The array **must be sorted**.
- Especially efficient when the target is **near the beginning** of the array or when the array size is **unbounded**.

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(1) | O(log n) | O(log n) |
| **Space** | O(1) | O(1) | O(1) |

---

## 6. Hashing Search

### Description
Uses a **hash table** to map values to indices, allowing near-instant lookups without traversing the array.

### When to use
- The array does **not need to be sorted**.
- Best when performing **frequent searches** on the same dataset.
- Requires extra memory for the hash table.

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(1) | O(1) | O(n) *(hash collision)* |
| **Space** | O(n) | O(n) | O(n) |

> ⬜ **Not yet implemented** — will be updated later.

---

## 7. Interpolation Search

### Description
An improvement over Binary Search. Instead of always picking the midpoint, the algorithm **estimates the position** of the target based on its value relative to the current range (similar to how you'd search in a phone book).

### When to use
- The array **must be sorted** and elements must be **uniformly distributed**.
- Performs poorly if the distribution is uneven.

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(1) | O(log log n) | O(n) |
| **Space** | O(1) | O(1) | O(1) |

---

## 8. Fibonacci Search

### Description
Uses Fibonacci numbers to divide the array into unequal parts, avoiding division when calculating the midpoint. Well-suited for systems where division is costly.

### When to use
- The array **must be sorted**.
- Preferred when **division is expensive** (embedded systems, older processors).

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(1) | O(log n) | O(log n) |
| **Space** | O(1) | O(1) | O(1) |

---

## 📊 Complexity Comparison

| Algorithm | Best | Average | Worst | Space | Sorted? |
|-----------|------|---------|-------|-------|---------|
| Linear Search | O(1) | O(n) | O(n) | O(1) | ❌ |
| Binary Search | O(1) | O(log n) | O(log n) | O(1) | ✅ |
| Ternary Search | O(1) | O(log₃ n) | O(log₃ n) | O(1) | ✅ |
| Jump Search | O(1) | O(√n) | O(√n) | O(1) | ✅ |
| Exponential Search | O(1) | O(log n) | O(log n) | O(1) | ✅ |
| Hashing Search | O(1) | O(1) | O(n) | O(n) | ❌ |
| Interpolation Search | O(1) | O(log log n) | O(n) | O(1) | ✅ |
| Fibonacci Search | O(1) | O(log n) | O(log n) | O(1) | ✅ |

---

## 🧭 When to Use Which Algorithm?

| Situation | Recommended Algorithm |
|-----------|----------------------|
| Small array, unsorted | Linear Search |
| Sorted array, general use | Binary Search |
| Uniformly distributed elements | Interpolation Search |
| Target likely near the beginning | Exponential Search |
| Avoid division (embedded systems) | Fibonacci Search |
| Frequent lookups, unsorted data | Hashing Search |
| Finding extremum of unimodal function | Ternary Search |
| Large array, simpler than Binary Search | Jump Search |

---

## 📁 Folder Structure

```
searching/
├── README.md
├── LinearSearch.cpp
├── BinarySearch.cpp
├── TernarySearch.cpp
├── JumpSearch.cpp
├── ExponentialSearch.cpp
├── HashingSearch.cpp
├── InterpolationSearch.cpp
└── FibonacciSearch.cpp
```