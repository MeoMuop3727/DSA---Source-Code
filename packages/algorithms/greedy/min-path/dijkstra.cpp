#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>
using namespace std;


class Graph {
    private:
        int size; // Size of Graph
        vector<vector<int>> matrix; // Adjancecy matrix - save weight of each vertex
        vector<int> dist; // Distance array of each vertex
    public:
        // Assign size for matrix and dist
        Graph(int size) : size(size) {
            matrix.resize(size, vector<int>(size, 0));
            dist.assign(size, INT_MAX);
        }
   
        void add_edge(int u, int v, int weight) {
            matrix[u][v] = weight; // Forward edge
            matrix[v][u] = weight; // Back edge
        }
       
        // We will use BFS in here
        // We will traversal all vertex to find a shortest path
        // Source: where we will begin
        // End: where we will finish
        int dijkstra(int source, int end) {
            priority_queue<
                pair<int,int>, // {dist, vertex}
                vector<pair<int,int>>,
                greater<pair<int,int>> // Sorting by compare dist
            > pq;
           
            vector<bool> visited(size, false);
       
            pq.push({
                matrix[source][source], source
            });
            dist[source] = 0;
       
            while (!pq.empty()) {
                pair<int,int> current = pq.top(); pq.pop();
               
                int u = current.second; // vertex u
               
                // If vertex u was visited
                // Pass else visited[u] = true
                if (visited[u]) continue;
                visited[u] = true;
               
                // Traversal all distance vertex of u
                for (int v = 0; v < size; v++) {
                    // If we have path between u and v
                    // And if dist[v] > dist[u] + weight
                    // Update dist[v] = dist[u] + weight
                    // push {weight, vertex v} into pq
                    if (!visited[v] && matrix[u][v] > 0 && dist[v] > dist[u] + matrix[u][v]) {
                        dist[v] = dist[u] + matrix[u][v];
                        pq.push({
                            matrix[u][v], v
                        });
                    }
                }
            }


            // Return the distance from source to end
            return dist[end];
        }
};


int main() {
    Graph graph(6);


    map<char,int> list_vertices = {
        {'A', 0},
        {'B', 1},
        {'C', 2},
        {'F', 3},
        {'E', 4},
        {'D', 5}
    };


    graph.add_edge(list_vertices['A'], list_vertices['B'], 3);  // A - B = 3
    graph.add_edge(list_vertices['A'], list_vertices['C'], 7);  // A - C = 7
    graph.add_edge(list_vertices['B'], list_vertices['C'], 2);  // B - C = 2
    graph.add_edge(list_vertices['B'], list_vertices['F'], 5);  // B - F = 5
    graph.add_edge(list_vertices['B'], list_vertices['E'], 9);  // B - E = 9
    graph.add_edge(list_vertices['C'], list_vertices['F'], 8);  // C - F = 8
    graph.add_edge(list_vertices['C'], list_vertices['E'], 8);  // C - E = 8
    graph.add_edge(list_vertices['F'], list_vertices['E'], 3);  // F - E = 3
    graph.add_edge(list_vertices['F'], list_vertices['D'], 4);  // F - D = 4
    graph.add_edge(list_vertices['E'], list_vertices['D'], 6);  // E - D = 6


    cout << graph.dijkstra(list_vertices['A'], list_vertices['D']);
   
    return 0;
}
