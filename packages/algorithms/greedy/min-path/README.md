# 🗺️ Shortest Path

Shortest Path is the problem of finding the path between two vertices in a graph such that the **sum of edge weights is minimized**. It is widely used in navigation systems, network routing, logistics, and game development.

---

## 📂 List of Algorithms

| # | Algorithm | Status |
|---|-----------|--------|
| 1 | [Dijkstra's Algorithm](#1-dijkstras-algorithm) | ✅ |

---

## Core Concepts

### Weighted Graph
A graph where each edge has an associated **cost or distance**. The shortest path minimizes the total weight from source to destination.

### Relaxation
The core operation in shortest path algorithms. For an edge (u, v) with weight w, **relaxation** updates the distance to v if going through u gives a shorter path:
```
if dist[u] + w < dist[v]:
    dist[v] = dist[u] + w
```

### Single-Source vs All-Pairs
- **Single-Source** — finds shortest paths from **one source** to all other vertices (e.g., Dijkstra).
- **All-Pairs** — finds shortest paths between **every pair** of vertices (e.g., Floyd-Warshall).

---

## 1. Dijkstra's Algorithm

### Description
Greedily selects the unvisited vertex with the **smallest known distance** from the source, relaxes all its neighbors, and marks it as visited. Repeats until all vertices are processed. Typically implemented with a **priority queue (min-heap)** for efficiency.

### When to use
- Graphs with **non-negative edge weights**.
- Single-source shortest path in road networks, maps, and routing.
- As a subroutine in other algorithms (e.g., Prim's MST, A\*).

### Complexity
| Implementation | Time | Space |
|----------------|------|-------|
| **Naive (array)** | O(V²) | O(V) |
| **Priority Queue (min-heap)** | O((V + E) log V) | O(V + E) |

> ⚠️ Does **not** work with **negative edge weights** — use Bellman-Ford instead.
> ⚠️ Does **not** find the correct path in graphs with **negative cycles** — use Floyd-Warshall instead.

---

## 📊 Shortest Path Algorithm Overview

For reference, here is how Dijkstra fits among other common shortest path algorithms:

| Algorithm | Negative Weights | Negative Cycles | Single/All-Pairs | Time Complexity |
|-----------|-----------------|-----------------|------------------|----------------|
| **Dijkstra** | ❌ | ❌ | Single-source | O((V + E) log V) |
| Bellman-Ford | ✅ | Detects | Single-source | O(V · E) |
| Floyd-Warshall | ✅ | Detects | All-pairs | O(V³) |

---

## 🧭 When to Use Dijkstra?

| Situation | Applicable? |
|-----------|------------|
| Non-negative edge weights | ✅ Yes |
| Finding shortest path on a map / GPS | ✅ Yes |
| Negative edge weights present | ❌ Use Bellman-Ford |
| Need all-pairs shortest paths | ❌ Use Floyd-Warshall |
| Graph has negative cycles | ❌ Use Floyd-Warshall |