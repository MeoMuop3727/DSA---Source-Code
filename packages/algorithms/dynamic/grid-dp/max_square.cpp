#include <bits/stdc++.h>
#include "tools.h"
using namespace std;

void createSquare(matrix &space) {
    srand(time(NULL));

    for (auto &row : space) 
        for (int &e : row)
            e = rand() % 2;
}

// Top - down
int helper(matrix &space, matrix &memo, int i, int j) {
    // Base case 
    // If memo[i][j] exsited
    // Get and return it
    if (memo[i][j] != -1) return memo[i][j];

    // Check to avoid overflow
    if (i < 0 || j < 0) return 0;

    // If space[i][j] is 0
    // This means we can not create square
    if (space[i][j] == 0) return memo[i][j] = 0;

    // Else
    // Return 1
    // This mean we can create square
    // With the minimum size is 1
    if (i == 0 || j == 0) return memo[i][j] = 1;
    
    int left = helper(space, memo, i - 1, j);
    int top = helper(space, memo, i, j - 1);
    int diag = helper(space, memo, i - 1, j - 1);

    // Else
    // Find the minimum of left, top and diag
    // Plus then 1
    return memo[i][j] = min({left, top, diag}) + 1;
}
int maxSquare(matrix &space) {
    int n = space.size(); // Row
    int m = space[0].size(); // Column

    matrix memo(n, vector<int>(m, -1));

    int maxSide = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            maxSide = max(maxSide, helper(space, memo, i, j));
    
    cout << endl;
    printMatrix(memo);

    // Return the size of square
    // By maxSide * maxSide
    return pow(maxSide, 2);    
}

// Bottom - up
int maxSquare(matrix &space) {
    int n = space.size(); // Row
    int m = space[0].size(); // Column

    matrix memo(n, vector<int>(m, 0));

    int maxSide = 0; // Save the maximum size of square

    // Traversal all elements
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            // If space[i][j] is 0
            // This means we can not create square
            // Skip it
            if (space[i][j] == 0) continue;

            // Base case
            // If the element on the border
            // Return 1 if it is not 0
            // This means we can create sqaure
            if (i == 0 || j == 0) memo[i][j] = 1;

            // Else
            // Find memo[i][j]
            // By finding minimum left, top and diag
            // Then plus 1
            else {
                int left = memo[i - 1][j];
                int top = memo[i][j - 1];
                int diag = memo[i - 1][j - 1];

                memo[i][j] = min({left, top, diag}) + 1;
            }

            // Compare maxSide and memo[i][j]
            // Because the square is random
            // Choose the maximum
            maxSide = max(maxSide, memo[i][j]);
        }
    
    // Return the size of square
    // By maxSide * maxSide
    return pow(maxSide, 2);
}

int main() {
    matrix space(6, vector<int>(6, 0));
    createSquare(space);
    
    printMatrix(space);

    cout << maxSquare(space) << "\n";

    return 0;
}