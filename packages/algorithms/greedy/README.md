# 💡 Greedy Algorithms

A Greedy Algorithm is a problem-solving technique that builds a solution **step by step**, always choosing the option that seems **best at the current moment** without reconsidering past choices. It is not a single algorithm, but a general **design strategy** applied to a wide variety of problems.

---

## 🧠 What is Greedy?

At each step, a greedy algorithm makes the **locally optimal choice** with the hope that it leads to a **globally optimal solution**. Unlike Dynamic Programming, it does not explore all possibilities — it commits to a decision and moves forward.

**General structure:**
1. Start with an empty solution.
2. At each step, pick the best available option according to a greedy criterion.
3. Add it to the solution if it is feasible.
4. Repeat until the solution is complete.

---

## ✅ When Does Greedy Work?

Greedy is not always correct. It produces an optimal solution only when the problem satisfies two key properties:

| Property | Description |
|----------|-------------|
| **Greedy Choice Property** | A globally optimal solution can be built by making locally optimal choices at each step. |
| **Optimal Substructure** | The optimal solution to the problem contains optimal solutions to its subproblems. |

> ⚠️ If a problem does **not** satisfy both properties, Greedy may produce an incorrect or suboptimal result. Consider **Dynamic Programming** or other approaches instead.

---

## 🆚 Greedy vs Dynamic Programming

| | Greedy | Dynamic Programming |
|--|--------|-------------------|
| **Decision** | One choice per step, never revisited | Explores all choices, picks the best |
| **Speed** | Generally faster | Generally slower |
| **Correctness** | Only for problems with greedy property | Works on a broader range of problems |
| **Memory** | O(1) extra in many cases | Often requires a table / memoization |
| **Example** | Dijkstra, Huffman, Kruskal | Knapsack, Floyd-Warshall, LCS |

---

## 📚 Classic Greedy Problems

### 🔹 Network Flow
Finding the maximum flow through a network from a source to a sink. Greedy-based augmenting path strategies (e.g., Ford-Fulkerson) are used to incrementally increase flow along available paths.

### 🔹 Shortest Path — Dijkstra's Algorithm
Finds the shortest path from a source node to all other nodes in a **weighted graph with non-negative edges**. At each step, greedily picks the unvisited node with the smallest known distance.

> ⚠️ Does **not** work with negative edge weights — use Bellman-Ford instead.

### 🔹 Minimum Spanning Tree (MST)
Finds the subset of edges that connects all vertices with the **minimum total weight**.

- **Kruskal's Algorithm** — sorts all edges by weight and greedily adds them if they don't form a cycle (uses Union-Find).
- **Prim's Algorithm** — greedily grows the MST by always adding the cheapest edge connecting the tree to a new vertex.

### 🔹 Data Compression — Huffman Coding
Builds an optimal **prefix-free binary encoding** by greedily merging the two least-frequent symbols at each step, producing shorter codes for more frequent characters.

---

## 🧭 When to Use Greedy?

| Situation | Greedy Applicable? |
|-----------|-------------------|
| Shortest path (non-negative weights) | ✅ Dijkstra |
| Minimum spanning tree | ✅ Kruskal / Prim |
| Data compression / encoding | ✅ Huffman Coding |
| Activity selection / scheduling | ✅ Yes |
| 0/1 Knapsack problem | ❌ Use Dynamic Programming |
| Negative edge weights (shortest path) | ❌ Use Bellman-Ford |
| Problems without greedy choice property | ❌ Use DP / Backtracking |