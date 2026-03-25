#include <bits/stdc++.h>
#include "tools.h"
using namespace std;

typedef vector<vector<int>> matrix;

void createSpace(matrix &space, int a, int b) {
    srand(time(NULL));

    for (auto &row : space)
        for (int &e : row) 
            e = rand() % (b - a + 1) + a;
}

// Top - down
int helper(matrix &space, matrix &memo, int i, int j) {
    // Base case
    // If i or j are overflow
    // Return 0 to avoid to result
    if (i < 0 || j < 0) return 0;

    // If i and j are 0
    // Return space at 0 and 0
    if (i == 0 && j == 0) return space[0][0];

    // If memo existed
    // Get and return it
    if (memo[i][j] != -1) return memo[i][j];

    // If i still is not 0
    // i - 1 to translate to the left by one level
    // Else
    // Assign left by INT_MAX to express can not access to left
    // Must choose another value
    int left = (i > 0) ? helper(space, memo, i - 1, j) : INT_MAX;
    // Same as i
    int top = (j > 0) ? helper(space, memo, i, j - 1) : INT_MAX;

    // Find min between left and top and plus it to space[i][j]
    return memo[i][j] = min(left, top) + space[i][j];
}
int mps(matrix &space) {
    int n = space.size(); // Row
    int m = space[0].size(); // Column

    matrix memo(n, vector<int>(m, -1));

    return helper(space, memo, n - 1, m - 1);
}

// Bottom - up
int mps(matrix &space) {
    int n = space.size(); // Row
    int m = space[0].size(); // Column

    matrix memo(n, vector<int>(m, 0));

    // Base case
    memo[0][0] = space[0][0];
    // All elements on top border
    // Are equal total of behind elements
    for (int i = 1; i < n; i++) memo[i][0] = memo[i - 1][0] + space[i][0];
    // Same as top
    for (int j = 1; j < m; j++) memo[0][j] = memo[0][j - 1] + space[0][j];

    // Traversal all element
    for (int i = 1; i < n; i++) 
        for (int j = 1; j < m; j++) {
            int left = memo[i - 1][j]; // Find left
            int top = memo[i][j - 1]; // Find right
            
            // Find min between left and top and plus it to space[i][j]
            memo[i][j] = min(left, top) + space[i][j];
        }

    return memo[n - 1][m - 1];
}

int main() {
    matrix space(6, vector<int>(6, 0));
    createSpace(space, 1, 9);
    
    printMatrix(space);

    cout << mps(space) << "\n";

    return 0;
}