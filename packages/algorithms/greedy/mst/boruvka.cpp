#include <bits/stdc++.h>
using namespace std;


class Graph {
    private:
        int size; // Size of graph
        vector<vector<int>> adj; // Adjacency list
        vector<vector<int>> cheapest; /* Save a smallest edge of each component
                                        with the respentative is index of root (parent) */
        vector<int> rnk, parent; // Store rank and root vertex to find


        int find(int u) { return (parent[u] == u) ? u : parent[u] = find(parent[u]); }


        void unite(int u, int v) {
            int s1 = find(u), s2 = find(v);


            if (s1 != s2) {
                if (rnk[s1] > rnk[s2]) parent[s2] = s1;
                else if (rnk[s1] < rnk[s2]) parent[s1] = s2;
                else parent[s2] = s1, rnk[s1]++;
            }
        }
    public:
        // Set up size for parent, rnk, and cheapest
        Graph(int size) : size(size) {
            parent.resize(size);
            rnk.resize(size);
            cheapest.resize(size);
            for (int i = 0; i < size; i++) parent[i] = i; // Set up initally for each element in parent
        }


        void add_edge(int u, int v, int weight) { adj.push_back({u, v, weight}); }


        int boruvka() {
            int ms = 0;
            int components = size; /* Components are edge united into a path,
                                    initally, each vertex is a component,
                                    mean components = size */


            // Loop until we only have two components
            // Find a smallest path in graph which will connect two components into one
            while (components > 1) {
                fill(cheapest.begin(), cheapest.end(), vector<int>(3, -1)); // Set up initally for cheapest, with element is {-1, -1, -1}


                // Traversal all edge in adj
                for (int i = 0; i < adj.size(); i++) {
                    int u = adj[i][0]; // Vertex u
                    int v = adj[i][1]; // vertex v
                    int w = adj[i][2]; // Weight of edge u - v
                   
                    int s1 = find(u), s2 = find(v); // Root of u (s1), v (s2)


                    // If they are not components (do not have a same root)
                    if (s1 != s2) {
                        // If the component with the respentative root is s1 which does not exist smallest edge
                        // or the weight of u - v is smaller than the weight of current edge (the root of edge u - v and
                        // edge which stored in cheapest are the same)
                        // Update new smallest edge
                        if (cheapest[s1][2] == -1 || cheapest[s1][2] > w) cheapest[s1] = adj[i];


                        // Same as s1
                        if (cheapest[s2][2] == -1 || cheapest[s2][2] > w) cheapest[s2] = adj[i];
                    }
                }


                // Traversal all vertices (root)
                for (int i = 0; i < size; i++) {
                    // If at that root which we are considering
                    // Exist a smallest edge
                    // MST it
                    if (cheapest[i][2] != -1) {
                        int u = cheapest[i][0];
                        int v = cheapest[i][1];
                        int w = cheapest[i][2];


                        int s1 = find(u), s2 = find(v);


                        if (s1 != s2) {
                            ms += w; // Update ms
                            unite(u, v); // Create MST
                            components--; // Decrease the number of components after each MST
                        }
                    }
                }
            }


            return ms;
        }
};


int main() {
    Graph graph(9);
   
    graph.add_edge(0, 1, 4);
    graph.add_edge(0, 7, 8);
    graph.add_edge(1, 2, 8);
    graph.add_edge(1, 7, 11);
    graph.add_edge(2, 3, 7);
    graph.add_edge(2, 5, 4);
    graph.add_edge(2, 8, 2);
    graph.add_edge(3, 4, 9);
    graph.add_edge(3, 5, 14);
    graph.add_edge(4, 5, 10);
    graph.add_edge(5, 6, 2);
    graph.add_edge(6, 7, 1);
    graph.add_edge(6, 8, 6);
    graph.add_edge(7, 8, 7);
   
    cout << graph.boruvka();
   
    return 0;
}
