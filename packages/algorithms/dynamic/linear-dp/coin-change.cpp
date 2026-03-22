#include <bits/stdc++.h>
#include <climits>
using namespace std;

// Top - down
// int coinHelper(vector<int> &coins, int money, vector<int> &memo) {

// }

// Bottom - down
int coinHelper(vector<int> &coins, int money, vector<int> &memo) {
    for (int i = 0; i <= money; i++) {
        for (int &c : coins) {
            //
            if (c <= i) {
                memo[i] = memo[i - c] + 1;
            }
        }
    }
}

int coin(vector<int> &coins, int money) {
    vector<int> memo(money + 1, INT_MAX);
    memo[0] = 0;
    return coinHelper(coins, money, memo);
}

int main() {

}