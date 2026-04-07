#include <bits/stdc++.h>
#include "../grid-dp/tools.h"
using namespace std;

int optimalBT(vector<int> &keys, vector<int> &freq, vector<int> &prefix) {
    int n = keys.size();

    matrix memo(n + 1, vector<int>(n + 1, INT_MAX));

    // Base case
    for (int i = 0; i <= n; i++) memo[i][i] = 0;

    for (int len = 2; len <= n + 1; len++) 
        for (int i = 0; i <= n - len + 1; i++) {
            int j = i + len - 1;

            // Total the sum in i...j
            int w = prefix[j] - prefix[i];
            
            for (int k = i; k < j; k++) {
                memo[i][j] = min(
                    memo[i][j],
                    memo[i][k] + memo[k + 1][j] + w
                );
            }
        }
    
    return memo[0][n];
}

int main() {
    vector<int> keys = {10,20,30,40};
    vector<int> freq = {4,2,6,3};

    vector<int> prefix = createPrefixSum(freq);

    cout << optimalBT(keys, freq, prefix) << "\n";

    return 0;
}