#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class GraphAdjacencyList {
public:
    GraphAdjacencyList(int numVertices) : numVertices(numVertices) {
        for (int i = 0; i < numVertices; i++) {
            adjacency_list[i] = {};
        }
    }

    bool addEdges(int v1, int v2) {
        if ((v1 >= 0 && v1 < numVertices) &&
            (v2 >= 0 && v2 < numVertices)) {
                adjacency_list[v1].push_back(v2);
                adjacency_list[v2].push_back(v1);
                return true;
            }
        return false;
    }

    bool removeEdges(int v) {
        if (isExist(v)) {
            adjacency_list.erase(v);
            for (auto& element : adjacency_list) {
                auto& nums = element.second;
                nums.erase(remove(nums.begin(), nums.end(), v), nums.end());
            }
            return true;
        }
        return false;
    }

    void printer() {
        for (auto element : adjacency_list) {
            cout << "[" << element.first << "] : ";
            for (auto i : element.second) {
                cout << "[" << i << "] ";
            }
            cout << "\n";
        }
    }
private:
    map<int, vector<int>> adjacency_list;
    int numVertices;

    bool isExist(int v) {
        return (adjacency_list.find(v) != adjacency_list.end());
    }
};
