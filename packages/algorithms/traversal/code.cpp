#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "tree.h"
#include "graph.h"
using namespace std;


// DFS for matrix
void DFSHelper(int start, vector<vector<int>> graph, vector<bool> &visited);
void DFS(int start, vector<vector<int>> graph);
// DFS for list
void DFSHelper(int start, map<int,vector<int>> graph, vector<bool> &visited);
void DFS(int start, map<int,vector<int>> graph);


// BFS for matrix
void BFS(int start, vector<vector<int>> graph);
// BFS for list
void BFS(int start, map<int,vector<int>> graph);
// BFS for tree
void BFS(Node *root) {
    queue<Node*> vertex;
    vertex.push(root);


    while (!vertex.empty()) {
        Node* current = vertex.front();
        vertex.pop();
        cout << current -> value << " ";


        if (current -> left) vertex.push(current -> left);
        if (current -> right) vertex.push(current -> right);
    }
}


int main() {
    vector<int> nums = {0,1,2,3,4};


    BinaryTree binary_tree = BinaryTree(nums);


    Graph graph = Graph(nums);


    for (int i = 0; i + 1 < nums.size(); i++) graph.addEdge(nums[i], nums[i + 1]);
    for (int i = 0; i + 2 < nums.size(); i++) graph.addEdge(nums[i], nums[i + 2]);


    cout << "===== Binary Tree =====" << endl;
    cout << "Pre-order: "; preorder(binary_tree.get_root()); cout << endl;
    cout << "In-order: "; inorder(binary_tree.get_root()); cout << endl;
    cout << "Post-order: "; postorder(binary_tree.get_root()); cout << endl;
    cout << "BFS: "; BFS(binary_tree.get_root()); cout << endl;


    cout << endl;


    cout << "===== Graph =====" << endl;
    cout << "DFS with list: \n"; DFS(2, graph.get_graph().first); cout << endl;
    cout << "DFS with matrix: \n"; DFS(1, graph.get_graph().second); cout << endl;
    cout << "BFS with list: \n"; BFS(3, graph.get_graph().first); cout << endl;
    cout << "BFS with matrix: \n"; BFS(4, graph.get_graph().second); cout << endl;


    return 0;
}


void DFSHelper(int start, vector<vector<int>> graph, vector<bool> &visited) {
    if (visited[start]) return;
    else { visited[start] = true; cout << start << " was visited\n"; }


    for (int i = 0; i < graph[start].size(); i++)
        if (graph[start][i] == 1) DFSHelper(i, graph, visited);
}


void DFS(int start, vector<vector<int>> graph) {
    vector<bool> visited; visited.resize(graph[start].size(), false);
    DFSHelper(start, graph, visited);
}


void DFSHelper(int start, map<int,vector<int>> graph, vector<bool> &visited) {
    if (visited[start]) return;
    else { visited[start] = true; cout << start << " was visited\n"; }


    for (auto i : graph[start]) DFSHelper(i, graph, visited);
}


void DFS(int start, map<int,vector<int>> graph) {
    vector<bool> visited; visited.resize(graph.size(), false);
    DFSHelper(start, graph, visited);
}


void BFS(int start, vector<vector<int>> graph) {
    queue<int> vertex;
    vector<bool> visited(graph.size(), false);


    vertex.push(start);
    visited[start] = true;


    while (!vertex.empty()) {
        int current = vertex.front();
        cout << current << " was visited\n";
        vertex.pop();


        for (int i = 0; i < graph[current].size(); i++)
            if (graph[current][i] == 1 && !visited[i]) {
                vertex.push(i);
                visited[i] = true;
            }
    }
}


void BFS(int start, map<int,vector<int>> graph) {
    queue<int> vertex;
    vector<bool> visited(graph.size(), false);


    vertex.push(start);
    visited[start] = true;


    while (!vertex.empty()) {
        int current = vertex.front();
        cout << current << " was visited\n";
        vertex.pop();


        for (int i : graph[current])
            if (!visited[i]) {
                vertex.push(i);
                visited[i] = true;
            }
    }
   
}
