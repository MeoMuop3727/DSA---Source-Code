#include <bits/stdc++.h>
#include <climits>
#include "tools.h"
using namespace std;

matrix createTriangle(int h, int a = 1, int b = 5) {
    srand(time(NULL));

    matrix result(h); // Build height of triangle

    for (int i = 0; i < h; i++)
        for (int j = 0; j <= i; j++)
            result[i].push_back(rand() % (b - a + 1) + a);
    
    return result;
}

// Top - down
int helper(matrix &triangle, matrix &memo, int i, int j) {
    // Base case
    // Build floor of the triangle
    if (i == (int)triangle.size() - 1) 
        return memo[i][j] = triangle[i][j];

    // If memo existed
    // Get and return it
    if (memo[i][j] != -1) return memo[i][j];

    // Go to left and right
    // Find the smallest element
    // Build from bottom to up
    // From second floor to top
    int downLeft = helper(triangle, memo, i + 1, j);
    int downRight = helper(triangle, memo, i + 1, j + 1);

    // Return the minimum path
    // The end, return memo[0][0] as the result
    return memo[i][j] = min(downLeft, downRight) + triangle[i][j];
}
int minimumTriangle(matrix &triangle) {
    int h = triangle.size();

    matrix memo(h); // Build height of memo
    for (int i = 0; i < h; i++) {
        memo[i].resize((int)triangle[i].size());
        fill(memo[i].begin(), memo[i].end(), -1);
    }

    return helper(triangle, memo, 0, 0);
}

// Bottom - up
int minimumTriangle(matrix &triangle) {
    int h = triangle.size();

    matrix memo(h); // Build height of memo
    for (int i = 0; i < h; i++)
        memo[i].resize((int)triangle[i].size());
    
    // Base case
    // Build floor of the triangle
    memo[h - 1] = triangle[h - 1];
    
    // Traversal all elements
    // From the second floor, from bottom - up
    for (int i = h - 2; i >= 0; i--) 
        // Traversal all element of each floor
        for (int j = 0; j <= i; j++) {
            /*
                Go left and right, considering what element is smallest
                For example,
                triangle:       memo:
                        6               0
                    5       7       5       7
                5 < 7, choose 5 and plus it to 6, replace 0 by result in memo
            */
            int downLeft = memo[i + 1][j];
            int downRight = memo[i + 1][j + 1];
            memo[i][j] = min(downLeft, downRight) + triangle[i][j];
        }
    
    // We will traversal until the top
    // Return the top as the result which we find
    return memo[0][0];
}

int main() {
    matrix triangle = createTriangle(6); // Create triangle with height is 6
    printMatrix(triangle);

    cout << minimumTriangle(triangle) << "\n";

    return 0;
}