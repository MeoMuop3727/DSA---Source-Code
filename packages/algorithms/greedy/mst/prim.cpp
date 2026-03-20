#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;


class Graph {
    private:
        int size; // Size of Graph
        vector<vector<int>> matrix; // Adjancecy matrix - save weight
        vector<int> key; // Save weight of spanning tree
    public:
        Graph(int size) : size(size) {
            matrix.resize(size, vector<int>(size, 0));
            key.assign(size, INT_MAX);
        }
       
        void add_edge(int u, int v, int weight) {
            matrix[u][v] = weight;
            matrix[v][u] = weight;
        }
       
        int prim(int source) {
            int ms = 0;
           
            priority_queue<
                pair<int,int>, // {weight, vertex}
                vector<pair<int,int>>,
                greater<pair<int,int>>
            > pq;
            vector<bool> visited(size, false);


            pq.push({0, source});
            key[source] = 0;
           
            while (!pq.empty()) {
                int u = pq.top().second; // Vertex u
                pq.pop();
               
                // If u was visited
                // Pass else visited[u] = true
                if (visited[u]) continue;
                visited[u] = true;
               
                for (int v = 0; v < size; v++) {
                    // If v was not visited
                    // And had a path from u -> v
                    // And weight of edge uv < key[v]
                    // true -> Update key[v] = weight uv
                    // and push {weight uv, vertex v} to pq
                    if (!visited[v] && matrix[u][v] > 0 && key[v] > matrix[u][v]) {
                        key[v] = matrix[u][v];
                        pq.push({matrix[u][v], v});
                    }
                }
            }
           
            for (int &i : key) ms += i; // Caculate minimum spanning (ms)
            return ms; // Return ms
           
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
   
    cout << graph.prim(0);
   
    return 0;
}
