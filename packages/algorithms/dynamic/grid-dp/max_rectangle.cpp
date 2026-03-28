#include <bits/stdc++.h>
#include "tools.h"
#include "../../add/add.h" // Import add_tools to get lrh
using namespace std;

// Top - down
int helper(matrix &space, matrix &memo, int i, int j) {
    // Base case    
    // If memo existed
    // Get and return it
    if (memo[i][j] != -1) return memo[i][j];

    // If space[i][j] = 0, 
    // Return and assign memo[i][j] = 0
    if (space[i][j] == 0) return memo[i][j] = 0;

    // If i == 0, and space is not 0
    // Return and assign memo[i][j] = 1
    if (i == 0) return memo[i][j] = 1;

    // Else
    // Return memo[i][j] = memo[i - 1][j] + 1
    // With memo[i - 1][j] = helper(i - 1, j)
    return memo[i][j] = helper(space, memo, i - 1, j) + 1;
}
int maxRectangle(matrix &space) {
    int n = space.size(); // Row
    int m = space[0].size(); // Column

    matrix memo(n, vector<int>(m, -1));

    int maxRect = 0;

    for (int i = 0; i < n; i++) {
        // Build a row by helper
        for (int j = 0; j < m; j++) 
            helper(space, memo, i, j);
        // After building a row, 
        // lrh that row and get the maximum side
        // Compare it with the current maximum by max function
        maxRect = max(maxRect, add_tools::lrh(memo[i]));
    }

    return maxRect;
}

// Bottom - up
int maxRectangle(matrix &space) {
    int n = space.size(); // Row
    int m = space[0].size(); // Column

    int maxRect = 0;

    matrix memo(n, vector<int>(m, 0));

    // Base case
    memo[0] = space[0];

    //  Traversal
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If space is 0
            // Skip and assign memo = 0
            if (space[i][j] == 0) memo[i][j] = 0;
            // Else
            // +1, as counting the number of row in column j 
            // is different from 0
            else
                memo[i][j] = memo[i - 1][j] + 1;
        }
        // After building a row, 
        // lrh that row and get the maximum side
        // Compare it with the current maximum by max function
        maxRect = max(maxRect, add_tools::lrh(memo[i]));
    }
    
    return maxRect;
}

int main() {
    matrix space(6, vector<int>(6,0));
    createSpace(space, 0, 1);

    printMatrix(space);

    cout << maxRectangle(space) << "\n";

    return 0;
} 