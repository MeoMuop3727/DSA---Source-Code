#include <bits/stdc++.h>
#include <climits>
#include "tools.h"
using namespace std;

// Top - down
int helper(matrix &space, matrix &memo, int i, int j) {
    int n = space.size(); // Row
    int m = space[0].size(); // Column

    // Base case
    // If i or j overflow
    // Return to avoid to the result
    if (i > n - 1 || j > m - 1) return 0;

    // If i and j is at n - 1 and m - 1
    // Return the minimum health that needs to join in
    if (i == n - 1 && j == m - 1)
        return memo[i][j] = max(1, 1 - space[n - 1][m - 1]);

    // If memo existed
    // Get and return it
    if (memo[i][j] != -1) return memo[i][j];

    // If i can go to continuely
    // Get the value at the space[i + 1][j]
    int goDown = (i <= n - 1) ? helper(space, memo, i + 1, j) : INT_MAX;
    // Same as i
    int goRight = (j <= m - 1) ? helper(space, memo, i, j + 1) : INT_MAX;

    // Check
    // Find the minimum space which needs smaller health
    // Then, minus it to the minimum health to space[i][j]
    // Return the memo[i][j] with the minimum health at i and j
    return memo[i][j] = max(
        1, 
        // The minimum need for space[i][j]
        min(goDown, goRight) - space[i][j]
    );
}
int dungeonGame(matrix &space) {
    int n = space.size(); // Row
    int m = space[0].size(); // Column

    matrix memo(n, vector<int>(m, -1));

    return helper(space, memo, 0, 0);
}

// Bottom - up
int dungeonGame(matrix &space) {
    int n = space.size(); // Row
    int m = space[0].size(); // Column

    matrix memo(n, vector<int>(m, 0));

    // Base case
    // Calculate the minimum health 
    memo[n - 1][m - 1] = max(1, 1 - space[n - 1][m - 1]);

    // Build the last row
    for (int i = n - 2; i >= 0; i--)
        memo[i][m - 1] = max(1, memo[i + 1][m - 1] - space[i][m - 1]);
        
    // Build the last column
    for (int j = m - 2; j >= 0; j--)
        memo[n - 1][j] = max(1, memo[n - 1][j + 1] - space[n - 1][j]);
    
    // Traversal all elements
    for (int i = n - 2; i >= 0; i--)
        for (int j = m - 2; j >= 0; j--) 
        // Check
        // Find the minimum space which needs smaller health
        // Then, minus it to the minimum health to space[i][j]
        // If it < 0, this means we gained lots of health, the health 
        // at that space is enough for we go to the next space
        // Else
        // That health is not enough
        // We need more health to pass over
            memo[i][j] = max(
                1,
                // The minimum need for space[i][j]
                min(memo[i + 1][j], memo[i][j + 1]) - space[i][j]
            );
    
    // Return the minimum health 
    // Which saved at 0 and 0
    // This means, return the start
    return memo[0][0]; 
}

int main() {
    matrix space(6, vector<int>(6, 0));
    createSpace(space, -5, 7);

    printMatrix(space);

    cout << dungeonGame(space) << "\n";

    return 0;
}