#include <bits/stdc++.h>
#include <climits>
#include "tools.h"
#include "../../add/add.h"
using namespace std;

// Top - down
int helper(matrix &space, matrix &memo, int i, int j) {
    // Base case
    if (i < 0 || j < 0) return 0;

    // 
    if (space[i][j] == 0) return 0;

    //
    if (i == 0 || j == 0) return 1;

    //
    if (memo[i][j] != -1) return memo[i][j];

    return memo[i][j] = helper(space, memo, i - 1, j) + space[i][j];
}
int maxRectangle(matrix &space) {
    int n = space.size(); // Row
    int m = space[0].size(); // Column

    int maxRect = INT_MIN;

    matrix memo(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            helper(space, memo, i, j);

    for (int i = 0; i < n; i++)
        maxRect = max(maxRect, add_tools::lrh(memo[i]));
    
    printMatrix(memo);
    
    return maxRect;
}

// Bottom - up
// int maxRectangle(matrix &space) {
//     int n = space.size(); // Row
//     int m = space[0].size(); // Column

//     int maxRect = INT_MIN;

//     matrix memo(n, vector<int>(m, 0));

//     // Base case
//     memo[0] = space[0];

//     //
//     for (int i = 1; i < n; i++)
//         for (int j = 0; j < m; j++) {
//             if (space[i][j] == 1)
//                 memo[i][j] = memo[i - 1][j] + space[i][j];
//             else if (space[i][j] == 0) memo[i][j] = 0;
//         }
    
//     //
//     for (int i = 0; i < n; i++)
//         maxRect = max(maxRect, add_tools::lrh(memo[i]));
    
//     return maxRect;
// }

int main() {
    matrix space(6, vector<int>(6,0));
    createSpace(space, 0, 1);

    printMatrix(space);

    cout << maxRectangle(space) << "\n";

    return 0;
} 