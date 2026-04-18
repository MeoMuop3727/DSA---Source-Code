#include <bits/stdc++.h>
#include <climits>
using namespace std;

// Top - down
int helper(vector<int> &coins, int amount, vector<int> &memo) {
    /* Base case */
    // If the amount which need to translate is equal zero
    // Return 0
    if (amount == 0) return 0;

    // Else if the amount is assigned
    // This mean we can not translate this money to coin
    // Return infinity
    else if (amount < 0) return INT_MAX;

    // If we calculated money
    // Get and return it
    if (memo[amount] != -1) return memo[amount];

    // Initally minimum of coins
    int minCoins = INT_MAX;

    // Traversal each coin to find the minimum
    // Coin need to translate to amount
    for (int &coin : coins) {
        // Create a var to save the number of coin translated
        int res = helper(coins, amount - coin, memo);

        // If it can translate
        // Update minCoins by minimum coins
        if (res != INT_MAX)
            minCoins = min(minCoins, res + 1);
    }

    // Assign the number of coin need to translate
    // To amount in memo
    // And return it
    return memo[amount] = minCoins;
}

// Bottom - up
int helper(vector<int> &coins, int amount, vector<int> &memo) {
    // Set up initally
    fill(memo.begin(), memo.end(), INT_MAX); 
    memo[0] = 0;

    // Traversal all amounts needed to translate
    for (int i = 1; i <= amount; i++) {
        // Traversal each coin
        // To find minimum coins
        for (int &coin : coins) {
            // If the number of coins is smaller than the amount
            // This mean we can translate coin to amount
            // And the remain coins, i - coin, particularly the coins which we
            // Need to calculate with the current coins to be equal amount,
            // is different from infinity,
            // This mean we calculated, and to avoid stack overflow
            // Find the minimum the coins need to translate to amount
            if (coin <= i && memo[i - coin] != INT_MAX) {
                memo[i] = min(memo[i], memo[i - coin] + 1);
            }
        }
    }

    // Return the coins need to translate to amount
    return memo[amount];
}

int coinChange(vector<int> &coins, int amount) {
    vector<int> memo(amount + 1, -1);
    int res = helper(coins, amount, memo);
    // If cannot find the number of coins need to 
    // Translate to the amount
    // Return -1
    // Else return the number of coins
    return res == INT_MAX ? -1 : res;
}

int main() {
    vector<int> coins = {1,4,6};
    cout << coinChange(coins, 9) << endl;
    return 0;
}