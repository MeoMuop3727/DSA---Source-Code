#include <iostream>
#include <vector>
using namespace std;

template <typename T>
using matrix = vector<vector<T>>; // Define 2D
template <typename T>
using matrices = vector<matrix>; // Defien 3D

int main() {
    matrix<int> m = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    // Traversal
    for (auto &row : m) {
        for (auto &e : row)
            cout << e << " ";
        cout << "\n";
    }
}