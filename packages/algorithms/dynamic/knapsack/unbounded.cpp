#include <bits/stdc++.h>
#include "../grid-dp/tools.h"
using namespace std;

/*
    ==================================================================
    Also improve and adjust the algorithm by use DP for 0/1 Knasack
    in method 2, link: "packages/algorithms/dynamic/knapsack/bool.cpp"
    ==================================================================

    =========================================================================
    They are the same as method 1, just adjust the condition in find maxValue
    and the condition at find include. You can try!!!
    =========================================================================
*/

int helper(vector<int> &values, vector<int> &weights, int maxWeight, int n, matrix &memo) {
    if (n == 0 || maxWeight == 0) return 0;

    if (memo[n][maxWeight] != -1) return memo[n][maxWeight];

    int pick = 0;
    if (weights[n - 1] <= maxWeight)
        // Different from the bool knapsack
        // You do not decrease n by 1 because you can recycle it
        // This mean, you can use it once again if you pick it
        pick = values[n - 1] + helper(values, weights, maxWeight - weights[n - 1], n, memo);
    
    // Else
    // You must decrease to choose another
    int notPick = helper(values, weights, maxWeight, n - 1, memo);

    return memo[n][maxWeight] = max(notPick, pick);
}
int Solution(vector<int> &values, vector<int> &weights, int maxWeight) {
    // In here, improved the performance by using DP
    int n = values.size();
    matrix memo(n + 1, vector<int>(maxWeight + 1, -1));
    return helper(values, weights, maxWeight, n, memo);
}

int main() {
    vector<int> values = {1,2,5,6};
    vector<int> weights = {2,3,4,5};
    int maxWeight = 8;

    cout << Solution(values, weights, maxWeight) << "\n";

    return 0;
}