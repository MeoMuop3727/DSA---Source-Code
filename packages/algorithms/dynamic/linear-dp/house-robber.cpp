#include <bits/stdc++.h>
using namespace std;

// Top - down
int helper(vector<int> &house, vector<int> &memo, int i) {
    /* Base case */
    // If the index i does not point out array
    // Return 0 to avoid effect value
    if (i < 0) return 0;

    // If the index i points out house[0], i == 0
    // Return it
    else if (i == 0) return house[0];
    
    // If the memo at i existed
    // Return it
    if (memo[i] != -1) return memo[i];

    // Test two cases
    // Skip: if skip house i, we only choose houses at i - 1
    // Take: if take house i, we can choose houses at i - 2, and plus to house[i]
    int skip = helper(house, memo, i - 1);
    int take = helper(house, memo, i - 2) + house[i];

    // Return the maximum cases
    return memo[i] = max(skip, take);
}

// Bottom - up
int helper(vector<int> &house, vector<int> &memo) {
    // Set up initally
    memo[0] = house[0];
    memo[1] = max(house[0], house[1]);

    // Traversal all houses 
    // From 2 to n
    for (int i = 2; i < house.size(); i++) 
        // Check case
        // Case 1: Don't choose house at i, we only choose houses at i - 1
        // Case 2: Choosing house at i, we can choose houses at i - 2, and plus 
        // To the value of house[i]
        memo[i] = max(memo[i - 1], memo[i - 2] + house[i]);

    // Return the last element
    return *(memo.end() - 1);
}

int houseRobber(vector<int> &house) {
    vector<int> memo((int)house.size(), -1);
    return helper(house, memo, (int)house.size() - 1);
}

int main() {
    vector<int> house = {2,7,9,3,1};
    cout << houseRobber(house) << "\n";
    return 0;
}