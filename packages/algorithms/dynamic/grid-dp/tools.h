#pragma
#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> matrix;

void printMatrix(matrix &space) {
    int n = space.size();
    int m = space[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cout << space[i][j] << " ";
        cout << "\n";
    }
}