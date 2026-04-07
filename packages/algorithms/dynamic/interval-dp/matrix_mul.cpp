#include <bits/stdc++.h>
#include "../grid-dp/tools.h"
using namespace std;

int matrixMul(vector<pair<int,int>> &matrices) {
    int n = matrices.size();

    matrix memo(n, vector<int>(n, INT_MAX));

    // Base case
    for (int i = 0; i < n; i++) memo[i][i] = 0;

    // Traversal
    for (int len = 2; len <= n; len++)
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            // Divide [i...j] into other ranges with k
            for (int k = i; k < j; k++) {
                // Calculate the number of ways to multi matices
                // Choose the minimum
                int mul = matrices[i].first * matrices[k].second * matrices[j].second;
                memo[i][j] = min(
                    memo[i][j],
                    memo[i][k] + memo[k + 1][j] + mul
                );
            }
        }

    return memo[0][n - 1];
}

int main() {
    vector<pair<int,int>> matrices = {
        {5,4}, {4,6}, {6,2}, {2,7}
    };

    cout << matrixMul(matrices) << "\n";

    return 0;
}