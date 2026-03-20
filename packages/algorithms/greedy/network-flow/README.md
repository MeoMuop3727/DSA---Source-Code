# 🌊 Network Flow

Network Flow is a class of problems in graph theory where we model a network as a directed graph with **capacities** on edges, and aim to find how much "flow" can be sent from a **source (s)** to a **sink (t)** while respecting those capacities.

---

## 📂 List of Algorithms

### Maximum Flow
| # | Algorithm | Status |
|---|-----------|--------|
| 1 | [Ford-Fulkerson](#1-ford-fulkerson) | ✅ |
| 2 | [Edmonds-Karp](#2-edmonds-karp) | ✅ |
| 3 | [Dinic's Algorithm](#3-dinics-algorithm) | ✅ |
| 4 | [Push-Relabel](#4-push-relabel) | ⬜ |
| 5 | [Capacity Scaling](#5-capacity-scaling) | ⬜ |

### Minimum Cut
| # | Topic | Status |
|---|-------|--------|
| 6 | [Minimum Cut (Max-Flow Min-Cut Theorem)](#6-minimum-cut) | ⬜ |

---

## Core Concepts

### Residual Graph
After sending flow along an edge, a **reverse edge** is added to allow flow to be "undone". This residual graph enables algorithms to correct earlier decisions.

### Augmenting Path
A path from source to sink in the residual graph where every edge has **remaining capacity > 0**. Sending flow along this path increases the total flow.

### Max-Flow Min-Cut Theorem
The **maximum flow** from source to sink equals the **minimum cut** capacity — the smallest total capacity of edges that, if removed, would disconnect source from sink.

---

## Part 1 — Maximum Flow Algorithms

## 1. Ford-Fulkerson

### Description
Repeatedly finds any **augmenting path** from source to sink using DFS and sends flow along it. Continues until no augmenting path exists.

### When to use
- Simple graphs with **integer capacities**.
- Educational introduction to max-flow concepts.

### Complexity
| | Time | Space |
|--|------|-------|
| **Complexity** | O(E · max_flow) | O(V + E) |

> ⚠️ May not terminate with **irrational capacities**. Prefer Edmonds-Karp for general use.

---

## 2. Edmonds-Karp

### Description
A refinement of Ford-Fulkerson that uses **BFS** instead of DFS to find the **shortest augmenting path** (fewest edges) at each step, guaranteeing polynomial time.

### When to use
- General-purpose maximum flow.
- When correctness and termination must be guaranteed regardless of capacity values.

### Complexity
| | Time | Space |
|--|------|-------|
| **Complexity** | O(V · E²) | O(V + E) |

---

## 3. Dinic's Algorithm

### Description
Builds a **level graph** using BFS, then finds **blocking flows** within it using DFS. Repeats until no augmenting path exists. Significantly faster than Edmonds-Karp in practice.

### When to use
- **Dense graphs** or graphs with large capacities.
- Competitive programming where performance is critical.
- Unit-capacity graphs (runs in O(E · √V)).

### Complexity
| | Time | Space |
|--|------|-------|
| **Complexity** | O(V² · E) | O(V + E) |

---

## 4. Push-Relabel

### Description
Instead of finding paths, it **pushes excess flow** from a node to its neighbors and **relabels** nodes when no push is possible. Works locally rather than along full paths.

### When to use
- **Dense graphs** where path-based methods are slow.
- When very high performance is required.

### Complexity
| | Time | Space |
|--|------|-------|
| **Complexity** | O(V² · √E) | O(V + E) |

> ⬜ **Not yet implemented** — will be updated later.

---

## 5. Capacity Scaling

### Description
A variant of Ford-Fulkerson that only considers augmenting paths with capacity **≥ a threshold Δ**, halving Δ each phase. Avoids sending tiny amounts of flow and improves efficiency.

### When to use
- Graphs with **large but varied capacities**.
- When Ford-Fulkerson is too slow due to many small augmentations.

### Complexity
| | Time | Space |
|--|------|-------|
| **Complexity** | O(E² · log(max_capacity)) | O(V + E) |

> ⬜ **Not yet implemented** — will be updated later.

---

## Part 2 — Minimum Cut

## 6. Minimum Cut

### Description
A **cut** is a partition of vertices into two sets S (containing source) and T (containing sink). The **cut capacity** is the total capacity of edges going from S to T. The **minimum cut** is the cut with the smallest capacity.

By the **Max-Flow Min-Cut Theorem**, the value of the maximum flow equals the capacity of the minimum cut. Therefore, the minimum cut can be found directly from the residual graph after running any max-flow algorithm:
- Run any max-flow algorithm to completion.
- Find all vertices reachable from the source in the **residual graph** — this is set S.
- All edges from S to T (non-reachable vertices) with full capacity form the minimum cut.

### When to use
- Network reliability analysis (find the weakest link).
- Image segmentation.
- Project selection / closure problems.

### Complexity
Same as the max-flow algorithm used (since min-cut is derived from max-flow).

> ⬜ **Not yet implemented** — will be updated later.

---

## 📊 Algorithm Comparison

| Algorithm | Time Complexity | Approach | Notes |
|-----------|----------------|----------|-------|
| Ford-Fulkerson | O(E · max_flow) | DFS augmenting path | May not terminate on irrationals |
| Edmonds-Karp | O(V · E²) | BFS augmenting path | Guaranteed termination |
| Dinic's | O(V² · E) | Level graph + blocking flow | Fastest in practice |
| Push-Relabel | O(V² · √E) | Local push operations | Best for dense graphs |
| Capacity Scaling | O(E² · log U) | Threshold-based augmentation | Good for large capacities |

---

## 🧭 When to Use Which Algorithm?

| Situation | Recommended Algorithm |
|-----------|----------------------|
| Simple introduction / small graphs | Ford-Fulkerson |
| General use, correctness guaranteed | Edmonds-Karp |
| Competitive programming / large graphs | Dinic's Algorithm |
| Very dense graphs | Push-Relabel |
| Large varied capacities | Capacity Scaling |
| Find minimum cut after max flow | Any max-flow + residual graph BFS |