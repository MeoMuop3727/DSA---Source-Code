#include <bits/stdc++.h>
#include "../grid-dp/tools.h"
using namespace std;

int burstBalloons(vector<int> &balloons) {
    int n = balloons.size();

    // Create new balloons with two border
    vector<int> newBalloons(n + 2);

    matrix memo(n + 2, vector<int>(n + 2, 0));

    // Create border is equal 1 for new balloons
    for (int i = 0; i <= n + 1; i++) {
        if (i == 0 || i == n + 1)
            newBalloons[i] = 1;
        else newBalloons[i] = balloons[i - 1];
    }

    // Traversal
    for (int len = 2; len <= n + 2; len++)
        for (int i = 0; i <= n - len + 2; i++) {
            int j = len + i - 1;
            // Divide [i;j] into (i; k-1) and (k+1; j)
            for (int k = i + 1; k < j; k++) {
                // Find the max score
                // We will choose k is the last balloon is bursted
                // We just take care to k and two neightbours, i and j
                // For example,
                // i [xxxxxkxxxx] j, with x is bursted balloons
                // We only have i, k and j
                int mul = newBalloons[i] * newBalloons[k] * newBalloons[j];
                memo[i][j] = max(
                    memo[i][j],
                    memo[i][k] // Burst in (i; k - 1]
                        + memo[k][j] // Burst in [k + 1; j)
                        + mul // Burst with three remain balloons, include i,k and j
                );
            }
        }

    return memo[0][n + 1];
}

int main() {
    vector<int> balloons = {3,1,5,8};
    
    cout << burstBalloons(balloons) << "\n";

    return 0;
}