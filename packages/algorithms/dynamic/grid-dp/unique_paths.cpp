#include <bits/stdc++.h>
#include "tools.h"
using namespace std;

typedef vector<vector<int>> matrix;

// Top - down
int helper(matrix &memo, int i, int j) {
    // Base case
    // If i or j is overflow
    // Return 0
    if (i < 0 || j < 0) return 0;

    // If calculated 
    // Get and return it
    if (memo[i][j] != -1) return memo[i][j];

    // Else if i == 0, or j == 0
    // This mean we have a[0][j] or a[i][0]
    // Return 1 to assign 
    if (i == 0 || j == 0) return memo[i][j] = 1;
    
    // Else
    // Assign for memo[i][j]
    // And return it
    return memo[i][j] = helper(memo, i - 1, j) + helper(memo, i, j - 1);
}

// Bottom - up
int helper(matrix &space, matrix &memo) {
    int n = space.size(); // Row
    int m = space[0].size(); // Column

    // Base case
    // For example
    /*
        {1,1,1,1,...}
        {1,0,0,0,...}
        {1,0,0,0,...}
        {1,0,0,0,...}
    */
   // For memo
    for (int i = 0; i < n; i++) memo[i][0] = 1;
    for (int j = 0; j < m; j++) memo[0][j] = 1;

    // Traversal all elements in memo
    // And update the number of ways to 
    // Go to it
    for (int i = 1; i < n; i++) 
        for (int j = 1;  j < m; j++) 
            memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
    
    // Return the number of ways to go to
    // Destination
    return memo[n - 1][m - 1];
}

int uniquePaths(matrix &space) {
    int n = space.size(); // Row
    int m = space[0].size(); // Column

    matrix memo(n, vector<int>(m, -1));
    
    return helper(space, memo);
}

int main() {
    matrix space(6, vector<int>(6,0));
    cout << uniquePaths(space) << endl;
    return 0;
}