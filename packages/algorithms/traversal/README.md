# 🌐 Traversal Algorithms

Traversal is the process of visiting every node in a data structure (such as a graph or tree) in a systematic way. It is a foundational operation used in pathfinding, cycle detection, topological sorting, connected component analysis, and many more applications.

---

## 📂 List of Algorithms

| # | Algorithm | Status |
|---|-----------|--------|
| 1 | [Depth-First Search (DFS)](#1-depth-first-search-dfs) | ✅ |
| 2 | [Breadth-First Search (BFS)](#2-breadth-first-search-bfs) | ✅ |

---

## 1. Depth-First Search (DFS)

### Description
Explores as **far as possible along each branch** before backtracking. Uses a **stack** (either explicitly or via recursion) to keep track of the path. Visits nodes in a depth-first manner — going deep into a branch before exploring siblings.

### When to use
- Detecting **cycles** in a graph.
- **Topological sorting** of a directed acyclic graph (DAG).
- Finding **connected components**.
- Solving **maze** and **pathfinding** problems.
- Generating **permutations / combinations** (backtracking).

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(V + E) | O(V + E) | O(V + E) |
| **Space** | O(V) | O(V) | O(V) |

> where `V` is the number of vertices and `E` is the number of edges.

---

## 2. Breadth-First Search (BFS)

### Description
Explores all neighbors of a node **level by level** before moving deeper. Uses a **queue** to process nodes in the order they are discovered. Guarantees the shortest path in an **unweighted graph**.

### When to use
- Finding the **shortest path** in an unweighted graph.
- **Level-order traversal** of a tree.
- Finding all nodes within a given **distance** from a source.
- Detecting **bipartite graphs**.
- Web crawling and **peer-to-peer network** exploration.

### Complexity
| | Best | Average | Worst |
|--|------|---------|-------|
| **Time** | O(V + E) | O(V + E) | O(V + E) |
| **Space** | O(V) | O(V) | O(V) |

> where `V` is the number of vertices and `E` is the number of edges.

---

## 📊 Complexity Comparison

| Algorithm | Time | Space | Data Structure | Shortest Path? |
|-----------|------|-------|---------------|----------------|
| DFS | O(V + E) | O(V) | Stack / Recursion | ❌ |
| BFS | O(V + E) | O(V) | Queue | ✅ *(unweighted)* |

---

## 🧭 When to Use Which Algorithm?

| Situation | Recommended Algorithm |
|-----------|----------------------|
| Shortest path in unweighted graph | BFS |
| Cycle detection | DFS |
| Topological sort | DFS |
| Level-order / layer-by-layer traversal | BFS |
| Pathfinding / backtracking / maze solving | DFS |
| Finding all nodes at distance k | BFS |

---

## 📁 Folder Structure

```
traversal/
├── README.md
├── DFS.cpp
└── BFS.cpp
```