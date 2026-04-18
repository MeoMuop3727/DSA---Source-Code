#include <bits/stdc++.h>
using namespace std;

// Top - down
int helper(vector<int> &arr, int i, vector<int> &memo) {
    // If the element existed
    // Return it
    if (memo[i] != -1) return memo[i];

    // Else
    // Assign by 1
    memo[i] = 1; // Base case

    // Traversal all elements from 0 to i
    for (int j = 0; j < i; j++) 
        // If it is increasing
        // Update memo[i] by maximum value
        if (arr[i] > arr[j])
            memo[i] = max(memo[i], memo[j] + 1);
    
    // Return memo[i]
    return memo[i];
}

int lis(vector<int> &arr) {
    // Set up initally
    vector<int> memo((int)arr.size(), -1);
    int result = 1;

    // Traversal all elements
    for (int i = 0; i < arr.size(); i++) 
        // Update maximum value for result
        result = max(result, helper(arr, i, memo));
    
    // Return result
    return result;
}

// Bottom - up
int lis(vector<int> &arr) {
    // Set up initally
    vector<int> memo((int)arr.size(), 1);

    // Traversal all elements
    for (int i = 1; i < arr.size(); i++) 
        for (int j = 0; j < i; j++) 
            // If they are raising
            // Update the maximum value for memo at i
            if (arr[i] > arr[j])
                memo[i] = max(memo[i], memo[j] + 1);
    
    // Because the maximum is random distribution in memo
    // Use max_element to find the maximum element in memo
    // And return it
    return *max_element(memo.begin(), memo.end());
}

int main() {
    vector<int> arr = {3,1,4,1,5,9,2,6};
    cout << lis(arr) << "\n";
    return 0;
}