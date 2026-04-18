#include <bits/stdc++.h>
#include "../grid-dp/tools.h"
using namespace std;

// Method 1 - Use Dynamic Programming (Bottom - up)
// In fact, we can show the include (maxtrix1D) in here
int Solution(vector<int> &value, vector<int> &weight, int maxWeight) {
    int w = maxWeight;
    int n = value.size();
    vector<int> include(n, 0);

    // We build memo with the size is (n + 1) * (maxWeight + 1)
    matrix memo(n + 1, vector<int>(w + 1, 0));

    // We set up the base case
    // In fact, when we create the memo with all elements is 0
    // We created base case
    /*
        0 0 0 0 ...
        0 ...
        0 ...
        ...
        The 0 is base case
    */
   // That is why we start at i = j = 1
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= w; j++) {
            // If the weight is fit or smaller than maxWeight
            // This means w - weight[i - 1] >= 0
            // To avoid overflow or bad value
            if (weight[i - 1] <= j) 
                memo[i][j] = max(
                    memo[i - 1][j],
                    memo[i - 1][j - weight[i - 1]] + value[i - 1]
                );
            // Else
            // Assign memo[i][j] = memo[i - 1][j] immidiately
            else memo[i][j] = memo[i - 1][j];
        }
    
    // Create a temporary var to avoid affecting to origin
    int temp_w = w;
    int temp_v = memo[n][w]; // maximum value

    // Traversal all items
    for (int i = n; i > 0; i--) {
        // If the weight of items is fit or smaller than maxWeight
        // And the value of items must be smaller than maxValue
        // True, get it and update maxWeight and maxValue
        // include[i - 1] = 1, this means we can get it
        if (weight[i - 1] <= w && value[i - 1] <= temp_v) {
            temp_w -= weight[i - 1];
            temp_v -= value[i - 1];
            include[i - 1] = 1;
        }
    }

    forEach(include); // Print include

    // The maximum value at the end of memo
    return memo[n][w];
}

// Method 2 - Use Recursion
// In fact, we can not use include (matrix1D) to present
// Elements which we got to put in the bag
int helper(vector<int> &value, vector<int> &weight, int maxWeight, int n) {
    if (n == 0 || maxWeight == 0) return 0;

    // In here, we have two chooses
    // Pick the items or do not pick the items

    // If we pick up
    // We must check if the weight of item
    // If it is fit or smaller than maxWeight
    // Pick it
    // Then update pick by
    /*
        =================================
        pick = value[i - 1] + helper(...)
        =================================
    */
    int pick = 0;
    if (weight[n - 1] <= maxWeight) 
        pick = value[n - 1] + helper(value, weight, maxWeight - weight[n - 1], n - 1);
    
    // If we choose do not pick this item
    // We skip it by n - 1
    // The maxWeight is still maintain
    int notPick = helper(value, weight, maxWeight, n - 1);

    // Return the maximum choose
    return max(pick, notPick);
}
int Solution(vector<int> &value, vector<int> &weight, int maxWeight) {
    int n = value.size();    
    return helper(value, weight, maxWeight, n);
}

int main() {
    vector<int> value = {1,2,5,6};
    vector<int> weight = {2,3,4,5};
    int maxWeight = 8;

    cout << Solution(value, weight, maxWeight) << "\n";

    return 0;
}