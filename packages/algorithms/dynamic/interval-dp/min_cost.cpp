#include <bits/stdc++.h>
#include "../grid-dp/tools.h"
using namespace std;

int minCost(vector<int> &stones, vector<int> &prefix_sum) {
    int n = stones.size();

    matrix memo(n, vector<int>(n, INT_MAX));

    // Base case
    for (int i = 0; i < n; i++) memo[i][i] = 0;

    // Traversal
    for (int len = 2; len <= n; len++)
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            // Because we created a summ array to avoid calculating again
            // But the range is not always true 
            // Therefore, we must find a new range
            // We will use the sum of [0 : j + 1] - [0 : i]
            // For example, we need value in [1:3] = {2,4,1} = 7
            // We will use [0:4] = {3,2,4,1} = 10 - [0:1] = {3} = 3 = 7 
            int sum = prefix_sum[j + 1] - prefix_sum[i];

            // Divide into each other ranges
            // [k : i] and [k + 1 : j]
            // Try all cases can occur
            // For example, we have [2,4,1]. We have two cases
            // 1: [2] and [4,1]
            // 2: [2,4] and [1]
            // Choose the min case
            for (int k = i; k < j; k++) {
                memo[i][j] = min(
                    memo[i][k] + memo[k + 1][j] + sum,
                    memo[i][j]
                );
            }
        }
    
    // The result is at the top - right of memo
    return memo[0][n - 1];
}

int main() {
    vector<int> stones = {3,2,4,1};
    vector<int> prefix_sum = createPrefixSum(stones);

    cout << minCost(stones, prefix_sum) << "\n";

    return 0;
}