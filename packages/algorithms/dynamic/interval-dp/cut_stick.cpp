#include <bits/stdc++.h>
#include "../grid-dp/tools.h"
using namespace std;

int minCost(vector<int> &cuts, int lenght) {
    int n = cuts.size();
    vector<int> newCuts(n + 2);

    for (int i = 0; i <= n + 1; i++) {
        if (i == 0) newCuts[i] = 0;
        else if (i == n + 1) newCuts[i] = lenght;
        else newCuts[i] = cuts[i - 1];
    }

    sort(newCuts.begin(), newCuts.end(), [](auto &a, auto &b) { return a < b; });

    matrix memo(n + 2, vector<int>(n + 2, INT_MAX));

    // Base case
    for (int i = 0; i <= n + 1; i++) memo[i][i] = 0; // Length = 1
    for (int i = 0; i < n + 1; i++) memo[i][i + 1] = 0; // Length = 2
    
    // Because we cannot divide with the length is 1 or 2
    // We must start with the length is 3
    for (int len = 3; len <= n + 2; len++)
        for (int i = 0; i <= n - len + 2; i++) {
            int j = len + i - 1;
            // Divide [i,j] into ranges
            // Calculate the cost we must expense
            // From i -> k, k -> j and i -> j
            // Compare it to previous value
            // Choose the min
            for (int k = i + 1; k < j; k++) {
                memo[i][j] = min(
                    memo[i][j],
                    memo[i][k] + memo[k][j] + (newCuts[j] - newCuts[i])
                );
            }
        }
    
    return memo[0][n + 1];
}

int main() {
    vector<int> cuts = {1,3,4,5};
    int lenght = 7;

    cout << minCost(cuts, lenght) << "\n";

    return 0;
}