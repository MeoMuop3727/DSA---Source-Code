#include <iostream>
#include <vector>
using namespace std;

class GraphAdjacnecyMaxtrix {
public:
    GraphAdjacnecyMaxtrix(int numVertices) : numVertices(numVertices) {
        adjacency_matrix.resize(numVertices);
        for (int i = 0; i < numVertices; i++) {
            adjacency_matrix[i].resize(numVertices);
            for (int j = 0; j < numVertices; j++) {
                adjacency_matrix[i][j] = false;
            }
        }
    }

    bool addEdges(int i, int j) {
        if ((i < numVertices && i >= 0)
            && (j < numVertices && j >= 0)) {
                adjacency_matrix[i][j] = true;
                adjacency_matrix[j][i] = true;
                return true;
            }
        return false;
    }

    bool removeEdges(int i, int j) {
        if ((i < numVertices && i >= 0)
            && (j < numVertices && j >= 0)) {
                adjacency_matrix[i][j] = false;
                adjacency_matrix[j][i] = false;
                return true;
            }
        return false;
    }

    void printer() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << "[" << adjacency_matrix[i][j] << "] ";
            }
            cout << endl;
        }
    }
private:
    const int numVertices;
    vector<vector<bool>> adjacency_matrix;
};
