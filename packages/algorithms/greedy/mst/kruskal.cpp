#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;


class Graph {
    private:
        int size; // Size of graph
        priority_queue<
            tuple<int,int,int>, // {weight, u, v}
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > adj; // Adjancecy list
        vector<int> parent; // Parent is a structure which saves roots of each vertex
        vector<int> rnk; // A var always helps the tree balance


        int find(int u) {
            // If we can find root
            // Return root
            // Else, assign each vertex a root, mean vertices point back root
            // The first time to find may be long, but the second will be faster
            return (parent[u] == u) ? u : parent[u] = find(parent[u]);
        }


        void unite(int x, int y) {
            // Merge two vertices into a edge
            int s1 = find(x), s2 = find(y); // Find root of x and y


            // If they do not have a same root
            if (s1 != s2) {
                // Check rank of each vertex
                // Which is larger, it will become a root
                // Else, choosing a random vertex and pointing back the other
                // Increasing the rank of pointed back node by one level to be higher than the other
                if (rnk[s1] < rnk[s2]) parent[s1] = s2;
                else if (rnk[s1] > rnk[s2]) parent[s2] = s1;
                else parent[s2] = s1, rnk[s1]++;
            }
        }
    public:
        Graph(int size) : size(size) {
            // Assign size for parent and rank
            parent.resize(size);
            rnk.resize(size);


            // Initally, all vertices point back themselves
            for (int i = 0; i < size; i++) parent[i] = i;
        }


        void add_edge(int u, int v, int weight) { adj.push({weight, u, v}); }


        int kruskal() {
            int ms = 0, count = 0;


            // Loop until count is smaller than size (the number of vertices) - 1
            while (count < size - 1) {
                tuple<int,int,int> current = adj.top(); adj.pop();


                int w = get<0>(current); // weight
                int u = get<1>(current); // vertex u
                int v = get<2>(current); // vertex v


                // If the root of u is different from v
                // ms (minimum spanning) += weight
                // count increases by one level
                // calling unite(u, v)
                if (find(u) != find(v)) {
                    ms += w;
                    count++;
                    unite(u, v);
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


    cout << graph.kruskal() << endl;


    return 0;
}
