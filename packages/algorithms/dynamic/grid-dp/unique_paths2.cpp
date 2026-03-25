#include <bits/stdc++.h>
#include "tools.h"
using namespace std;

typedef vector<vector<int>> matrix;

void createObstacles(matrix &space, int number) {
    int n = space.size(); // Row
    int m = space[0].size(); // Column

    // Create obstacles in space
    // By random
    srand(static_cast<unsigned int>(time(0)));
    
    for (int i = 0; i < number; i++) 
        space[1 + rand() % (n - 2)][1 + rand() % (m - 2)] = 1;
}

// Top - down
int helper(matrix &space, matrix &memo, int i, int j) {
    // Base case
    // If i and j overflow
    // Return 0 to advoid to the result
    if (i < 0 || j < 0) return 0;
    
    // If the space at i and j is equal 1
    // This mean we have been blocked
    // Return 0 to present do not have path
    if (space[i][j] == 1) return 0;

    // Else return 1
    // For each element arr[i][0] or arr[0][j]
    if (i == 0 || j == 0) return 1;
    
    //  If memo existed
    // Get and return it
    if (memo[i][j] != -1) return memo[i][j];

    return memo[i][j] = helper(space, memo, i - 1, j) + helper(space, memo, i, j - 1);
}
int uniquePaths2(matrix &space) {
    int n = space.size(); // Row
    int m = space[0].size(); // Colunm

    // Set up initally
    matrix memo(n, vector<int>(m, -1));

    return helper(space, memo, n - 1, m - 1);
}

// Bottom - up
int uniquePaths2(matrix &space) {
    int n = space.size(); // Row
    int m = space[0].size(); // Colunm

    //  Set up  initally
    matrix memo(n, vector<int>(m, 0));

    // Base case
    for (int i = 0; i < n; i++)
        // If the space on border is different from 1
        // Assign this space in memo by 1
        // To describe it to have a path
        if (space[i][0] != 1) memo[i][0] = 1;
    for (int j = 0; j < m; j++)
        // Same with row i
        if (space[0][j] != 1) memo[0][j] = 1;
        
    // Traversal all element in space
    for (int i = 1; i < n; i++) 
        for (int j = 1; j < m; j++) 
            // If they are not blocked
            // Update in memo
            if (space[i][j] != 1) 
                memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
    
    return memo[n - 1][m - 1];
}

int main() {
    matrix space(6, vector<int>(6, 0));
    createObstacles(space, 12);

    printMatrix(space);

    cout << uniquePaths2(space) << "\n";

    return 0;
}
