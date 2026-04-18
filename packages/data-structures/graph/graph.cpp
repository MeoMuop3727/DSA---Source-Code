#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
    /*
        In lesson 1, we learned about how to show a graph. First,
        we can use matrix or list, but in here, we will use list to improve
        memory also installs easily.
            + First, we will use map to create a vertex which will save a lot
        others (edges which connected vertexs)
            + Second, we will make two functions. First function will build a
        vertex and second function will add edges
    */
public:
    Graph() {}

    void addVertex(int vertex) {
        // This function will create a new vertex
        m_graph[vertex] = {}; // Vertex was created
    }

    void addEdges(int vertex_1, int vertex_2) {
        // This function will add vertex 2 (edges) into vertex 1
        // Also vertex 1 will be added into vertex 2
        // This is mean we will build a undirected graph
        m_graph[vertex_1].push_back(vertex_2);
        m_graph[vertex_2].push_back(vertex_1);
    }

    void removeVertex(int vertex) {
        // This function will delete a element if it is exist
        if (isExist(vertex)) {
            m_graph.erase(vertex); // Delete a vertex
            for (auto& element : m_graph) { // Delete all edges of that vertex
                auto& nums = element.second;
                nums.erase(remove(nums.begin(), nums.end(), vertex), nums.end());
            }
        }
    }

    void printer() {
        for (const auto& element : m_graph) {
            cout << "[" << element.first << "]" << " : ";
            for (int vertexs : element.second) {
                cout << vertexs << " ";
            }
            cout << endl;
        }
    }
private:
    map<int, vector<int>> m_graph;

    bool isExist(int vertex) {
        return (m_graph.find(vertex) != m_graph.end());
    }
};
