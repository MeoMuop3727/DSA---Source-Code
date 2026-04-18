#include <bits/stdc++.h>
#include "../grid-dp/tools.h"
#include "../../add/add.h"
using namespace std;

int lps(const string &str) {
    /* In here, we will have two approaches */

    // 1. Use to_reverse in tools.h to make a reversed string
    // from inital string, using lcs1 from add.h.

    // string reStr = to_reverse(str);
    // return add_tools::lcs1(str, reStr);

    // 2. Build everything from 0

    int n = str.size(); 

    matrix memo(n, vector<int>(n, 0));

    // Base case
    for (int i = 0; i < n; i++) memo[i][i] = 1;

    // Traversal
    for (int len = 2; len <= n; len++)
        for (int i = 0; i <= n - len; i++) {
            // Determinate the index j, where we will end
            int j = len + i - 1; 
            
            // If the str[i] == str[j],
            // This means they are palindromic 
            // For example, str = bab <=> str' = bab (after making symmetrical)
            // Calculate the length, by the length from i + 1 to j - 1, then plusing 2
            if (str[i] == str[j])
                memo[i][j] = memo[i + 1][j - 1] + 2;

            // Else
            // Compare between the lengths in string
            // Length 1: i + 1 --> j
            // Length 2: i --> j - 1
            // For example,
            // bda <=> length 1: bd, and length 2: da
            // Choose max
            else 
                memo[i][j] = max(memo[i + 1][j], memo[i][j - 1]);
        }

    // The maximum at the top - right of memo
    return memo[0][n - 1];
}

int main() {
    string str = "bbbdb";

    cout << lps(str) << "\n";

    return 0;
}