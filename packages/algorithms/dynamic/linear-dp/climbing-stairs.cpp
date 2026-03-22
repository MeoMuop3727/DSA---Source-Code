#include <bits/stdc++.h>
using namespace std;

// Top - down
int climbHelper(int i, vector<int> &memo) {
    if (i <= 2) return i; // Base case
   
    // If memo[i] existed
    // Return memo[i]
    if (memo[i] != -1) return memo[i];

    // Else
    // Assign memo[i] and return
    return memo[i] = climbHelper(i - 1, memo) + climbHelper(i - 2, memo);
}

// Bottom - up
int climbHelper(int i, vector<int> &memo) {
    // Set up initally
    // Base case
    memo[1] = 1; memo[2] = 2;

    for (int j = 3; j <= i; j++) 
        memo[j] = memo[j - 1] + memo[j - 2]; //
    
    return memo[i];
}

int climbing(int i) {
    // Because of knowing the size
    // We do not need to set up it
    // With a huge size
    vector<int> memo(i + 1, -1);
    return climbHelper(i, memo);
}

int main() {
    cout << climbing(5) << "\n";
    return 0;
}