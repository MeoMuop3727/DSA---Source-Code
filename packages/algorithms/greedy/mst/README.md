# 🌲 Minimum Spanning Tree (MST)

A Minimum Spanning Tree is a subset of edges in a **connected, undirected, weighted graph** that connects all vertices together with **no cycles** and the **minimum possible total edge weight**. It spans all V vertices using exactly V-1 edges.

---

## 📂 List of Algorithms

| # | Algorithm | Status |
|---|-----------|--------|
| 1 | [Kruskal's Algorithm](#1-kruskals-algorithm) | ✅ |
| 2 | [Prim's Algorithm](#2-prims-algorithm) | ✅ |
| 3 | [Borůvka's Algorithm](#3-borůvkas-algorithm) | ✅ |
| 4 | [Filter-Kruskal](#4-filter-kruskal) | ⬜ |
| 5 | [Chazelle's Algorithm](#5-chazelles-algorithm) | ⬜ |

---

## Core Concepts

### Spanning Tree
A subgraph that includes **all vertices** of the graph and is a **tree** (connected with no cycles). A graph with V vertices has a spanning tree with exactly V-1 edges.

### Cut Property
For any cut (partition of vertices into two sets), the **minimum weight edge** crossing the cut is always part of some MST. This property is the foundation of all greedy MST algorithms.

### Cycle Property
For any cycle in the graph, the **maximum weight edge** in the cycle is never part of any MST (assuming unique edge weights).

### Union-Find (Disjoint Set Union)
A data structure used by Kruskal's and Borůvka's algorithms to efficiently track which vertices are in the same connected component, enabling fast cycle detection.

---

## 1. Kruskal's Algorithm

### Description
Sorts all edges by weight, then greedily adds edges one by one — skipping any edge that would form a **cycle** — until V-1 edges have been added. Uses **Union-Find** for efficient cycle detection.

### When to use
- **Sparse graphs** (few edges).
- When edges are already sorted or easy to sort.
- Simple and widely used in practice.

### Complexity
| | Time | Space |
|--|------|-------|
| **Complexity** | O(E log E) | O(V + E) |

---

## 2. Prim's Algorithm

### Description
Starts from an arbitrary vertex and greedily grows the MST by always adding the **cheapest edge** that connects a vertex inside the tree to one outside. Uses a **priority queue (min-heap)** for efficiency.

### When to use
- **Dense graphs** (many edges).
- When the graph is given as an adjacency matrix.
- When starting from a specific vertex is natural.

### Complexity
| Implementation | Time | Space |
|----------------|------|-------|
| **Naive (array)** | O(V²) | O(V) |
| **Priority Queue (min-heap)** | O((V + E) log V) | O(V + E) |

---

## 3. Borůvka's Algorithm

### Description
In each phase, every component independently finds its **cheapest outgoing edge** and adds it to the MST. Components then merge. The number of components halves each phase, so it completes in O(log V) phases.

### When to use
- **Parallel and distributed computing** (each component works independently).
- Dense graphs where parallel processing is available.
- As a subroutine in more advanced MST algorithms.

### Complexity
| | Time | Space |
|--|------|-------|
| **Complexity** | O(E log V) | O(V + E) |

---

## 4. Filter-Kruskal

### Description
An improvement over Kruskal's algorithm for large graphs. Randomly selects a **pivot edge weight**, filters out edges heavier than the pivot that lie within the same component, then recursively applies the same strategy. Reduces unnecessary sorting work.

### When to use
- Very **large sparse graphs** where sorting all edges upfront is expensive.
- When average-case performance matters more than worst-case.

### Complexity
| | Time | Space |
|--|------|-------|
| **Expected** | O(E log log V) | O(V + E) |

> ⬜ **Not yet implemented** — will be updated later.

---

## 5. Chazelle's Algorithm

### Description
A theoretically optimal MST algorithm using a **soft heap** data structure to achieve near-linear time. It is the fastest known deterministic MST algorithm, but extremely complex to implement in practice.

### When to use
- Theoretical interest and research.
- Extremely large graphs where even O(E log log V) is too slow.

### Complexity
| | Time | Space |
|--|------|-------|
| **Complexity** | O(E · α(V)) | O(V + E) |

> where `α` is the inverse Ackermann function — essentially constant for all practical inputs.
> ⬜ **Not yet implemented** — will be updated later.

---

## 📊 Algorithm Comparison

| Algorithm | Time Complexity | Best For | Data Structure |
|-----------|----------------|----------|---------------|
| Kruskal | O(E log E) | Sparse graphs | Union-Find |
| Prim | O((V + E) log V) | Dense graphs | Priority Queue |
| Borůvka | O(E log V) | Parallel computation | Union-Find |
| Filter-Kruskal | O(E log log V) expected | Very large sparse graphs | Union-Find |
| Chazelle | O(E · α(V)) | Theoretical optimum | Soft Heap |

---

## 🧭 When to Use Which Algorithm?

| Situation | Recommended Algorithm |
|-----------|----------------------|
| Sparse graph, simple implementation | Kruskal |
| Dense graph | Prim |
| Parallel / distributed system | Borůvka |
| Very large graph, best average performance | Filter-Kruskal |
| Theoretical / research purposes | Chazelle |