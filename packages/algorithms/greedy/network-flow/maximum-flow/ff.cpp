#include <bits/stdc++.h>
#include <climits>
using namespace std;


class Graph {
    private:
        int size; // Size of graph
        vector<vector<int>> matrix; // Adjancecy matrix
    public:
        // Assign size for matrix
        Graph(int size) : size(size) { matrix.resize(size, vector<int>(size, 0)); }


        void add_edge(int edge_u, int edge_v, int capacity) {
            // Forward edge
            // The flow and capacity are equal
            matrix[edge_u][edge_v] = capacity;
        }


        bool find_augmenting_path(int edge_s, int edge_t, vector<int> &path) {


            /*
                We will use BFS in here to find a route from S to T
                and save it into path.
            */


            vector<bool> visited(size, false);
            queue<int> q;
            q.push(edge_s); visited[edge_s] = true; path[edge_s] = -1;


            while (!q.empty()) {
                int current = q.front(); q.pop();


                for (int v = 0; v < size; v++) {
                    int flow = matrix[current][v];
                    // If the vertex is not visited and we can send flow continuely
                    if (!visited[v] && flow > 0) {
                        // If the vertex is T
                        // This mean we found a path from S -> T
                        if (v == edge_t) {
                            path[v] = current;
                            return true;
                        }


                        path[v] = current; // Save the route
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }


            // If we can not reach the sink
            // Return false
            return false;
        }


        int FFAlgorithm(int edge_s, int edge_t) {
            vector<int> path(size, 0); // Create the path save a route S -> T
            int max_flow = 0;


            while (find_augmenting_path(edge_s, edge_t, path)) {
                int temp_flow = INT_MAX;


                // Find the maximum flow can send from S -> T from saved path
                for (int edge_v = edge_t; edge_v != edge_s; edge_v = path[edge_v]) {
                    int edge_u = path[edge_v];
                    temp_flow = min(temp_flow, matrix[edge_u][edge_v]);
                }


                // Update the flow of forward and back edge
                // Forward edge will decrease until 0. This mean we can not use this way
                // Back edge will increase until by capacity. This mean we can use it to backtrack
                for (int edge_v = edge_t; edge_v != edge_s; edge_v = path[edge_v]) {
                    int edge_u = path[edge_v];
                    matrix[edge_u][edge_v] -= temp_flow; // Froward edge
                    matrix[edge_v][edge_u] += temp_flow; // Back edge
                }


                max_flow += temp_flow;
            }


            return max_flow;
        }
};


int main() {
    Graph graph(6);


    graph.add_edge(0,1,10);
    graph.add_edge(0,2,10);
    graph.add_edge(1,3,4);
    graph.add_edge(1,4,8);
    graph.add_edge(1,2,2);
    graph.add_edge(2,4,9);
    graph.add_edge(3,5,10);
    graph.add_edge(4,3,6);
    graph.add_edge(4,5,10);


    cout << "Max flow: " << graph.FFAlgorithm(0,5);


    return 0;
}
