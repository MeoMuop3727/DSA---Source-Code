#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;


class Edge {
    public:
        int vertex; // The index of vertex u
        int flow; // The flow contained
        int capacity; // The max flow which edge can contain
        int reverse; // The index of vertex v (reverse edge)
        Edge(int vertex, int flow, int capacity, int reverse)
            : vertex(vertex), flow(flow), capacity(capacity), reverse(reverse) {}
};


class Graph {
    private:
        vector<vector<Edge>> adj; // The adjancecy list
        vector<int> level; // Level of edges
        int size; // Size of graph
   
    public:
        // Set up size for adjancecy list and level
        Graph(int size) : size(size) { adj.resize(size); level.resize(size); }


        void add_edge(int edge_u, int edge_v, int capacity) {
            // Create forward edge: edge u -> edge v (main way)
            // The main way has flow = 0 and capacity = capacity
            Edge forward(edge_v, 0, capacity, (int)adj[edge_v].size());
            // Create back edge: edge v -> edge u (reverse edge)
            // The reverse edge has flow and capacity are equal zero
            Edge back(edge_u, 0, 0, (int)adj[edge_u].size());


            // Connect (Create an edge) two vertexes
            adj[edge_u].push_back(forward); // Main edge
            adj[edge_v].push_back(back); // Reverse edge
        }


        bool assign_level(int edge_s, int edge_t) {
            /*
                We will use BFS in here to assign level for all edges
                We also check in graph if it has a route from Source (S) to Sink (T)


                Include:
                    + edge_s: The index of vertex source (S)
                    + edge_t: The index of vertex sink (T)
            */


            fill(level.begin(), level.end(), -1);   // Assign all edge by -1
                                                    // This mean they do not have level
            level[edge_s] = 0; // The starting edge (Source)


            queue<int> q; q.push(edge_s); // Save edges


            while (!q.empty()) {
                int current = q.front(); q.pop();


                for (int i = 0; i < adj[current].size(); i++) {
                    Edge &edge = adj[current][i];
                    // The edge does not assign level and the capacity is not full
                    if (level[edge.vertex] < 0 && edge.capacity > edge.flow) {
                        level[edge.vertex] = level[current] + 1;
                        q.push(edge.vertex);
                    }
                }
            }


            // If we can reach the sink
            // Return true else false
            return (level[edge_t] >= 0) ? true : false;
        }


        int send_flow(int edge_s, int flow, int edge_t, vector<int> &start) {
            /*
                We will use DFS in here to send the maximum flow which we can send
               
                Include:
                    + edge_s, edge_t are index of vertex source and vertex sink
                    + flow: The max flow we can send between two vertexes (an edge), start with INT_MAX (or unsigned infinity)
                    + start: Store all vertexes (or edges) are visited, they also can use like an index to traversal
            */
           
            // If we went to the end of graph (sink)
            // Return flow
            if (edge_s == edge_t) return flow;


            // Traversal all edges in adjancecy list
            for (; start[edge_s] < adj[edge_s].size(); start[edge_s]++) {
                Edge &edge = adj[edge_s][start[edge_s]];


                // If the level between two vertexes is 1 and we can send flow continuely
                if (level[edge.vertex] == level[edge_s] + 1 && edge.capacity > edge.flow) {
                    // The max flow between edge_s and connected edges with it
                    int current_flow = min(flow, edge.capacity - edge.flow);
                    // The real flow can send to sink
                    int temp_flow = send_flow(edge.vertex, current_flow, edge_t, start);


                    if (temp_flow > 0) {
                        // Update flow in edge and reverse edge
                        edge.flow += temp_flow;
                        adj[edge.vertex][edge.reverse].flow -= temp_flow;
                        return temp_flow;
                    }
                }
            }


            return 0;
        }


        int DinicAlgorithm(int edge_s, int edge_t) {
            if (edge_s == edge_t) return -1;


            int max_flow = 0;


            while (assign_level(edge_s, edge_t)) {
                vector<int> start(size, 0); // Create starting array to save visited vertexes (or edges)
                while (int flow = send_flow(edge_s, INT_MAX, edge_t, start)) max_flow += flow;
            }
           
            return max_flow;
        }
};


int main() {
    Graph graph = Graph(6);


    graph.add_edge(0, 1, 10);
    graph.add_edge(0, 2, 10);
    graph.add_edge(1, 2, 2);
    graph.add_edge(1, 3, 4);
    graph.add_edge(1, 4, 8);
    graph.add_edge(2, 4, 9);
    graph.add_edge(3, 5, 10);
    graph.add_edge(4, 3, 6);
    graph.add_edge(4, 5, 10);


    cout << "Max flow: " << graph.DinicAlgorithm(0, 5); // Max flow: 19


    return 0;
}
