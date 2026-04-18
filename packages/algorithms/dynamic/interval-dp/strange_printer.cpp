#include <bits/stdc++.h>
#include "../grid-dp/tools.h"
using namespace std;

int strangePrinter(const string &str) {
    int n = str.length();

    matrix memo(n, vector<int>(n, n));

    // Base case
    // Each char always have one way to print
    for (int i = 0; i < n; i++) memo[i][i] = 1;

    // Traversal
    for (int len = 2; len <= n; len++)
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            // Divide into ranges
            for (int k = i; k < j; k++) {
                // Check, 
                // If k + 1 > j - 1, this means we segmentation fault
                // To avoid it, we must check, if true return 0 else memo[k + 1][j - 1]
                // This stitution occur if str[k] == str[j]
                // For example,
                // We have range, i....k(k+1)j, if the str[k] == str[j], this mean they have
                // The same char, we only need to print once, j - 1 == k + 1 so that they have same key to print
                int mid = (k + 1 > j - 1) ? 0 : memo[k + 1][j - 1];
                if (str[k] == str[j])
                    memo[i][j] = min(memo[i][j], memo[i][k] + mid);
                
                // Else
                // They are not same key
                // And because k is behind j, we do not need to take care about segmentation fault
                else    
                    memo[i][j] = min(memo[i][j], memo[i][k] + memo[k + 1][j]);
            }
        }

    return memo[0][n - 1];
}

int main() {
    string chars = "abcb";

    cout << strangePrinter(chars) << "\n";

    return 0;
}