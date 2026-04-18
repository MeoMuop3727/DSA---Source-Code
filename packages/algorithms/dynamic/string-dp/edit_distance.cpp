#include <bits/stdc++.h>
#include "../grid-dp/tools.h"
using namespace std;

int editDistance(const string &s1, const string &s2) {
    int n = s1.size(); // Row
    int m = s2.size(); // Column

    matrix memo(n + 1, vector<int>(m + 1, 0));

    // Base case
    // In row, just using deletion
    // memo[i][0] means we deleted element i
    // Make the number of i started elements of s1 to 0 started elements of s2
    for (int i = 0; i <= n; i++) memo[i][0] = i;

    // Same as row
    // But we use insertion
    for (int j = 0; j <= m; j++) memo[0][j] = j;

    // Traversal all elements
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) {
            // If two chars is equal
            // Only using transition between chars
            if (s1[i - 1] == s2[j - 1]) 
                memo[i][j] = memo[i - 1][j - 1];
            
            // Else
            // Find the smallest transition
            // Use then it and plus to 1
            else {
                int del = memo[i - 1][j]; // Delete
                int ins = memo[i][j - 1]; // Insert
                int repl = memo[i - 1][j - 1]; // Replace

                memo[i][j] = min({ins, del, repl}) + 1;
            }
        }
    
    // Return the result at memo[n][m]
    return memo[n][m];
}

int main() {
    string s1 = "horse";
    string s2 = "ros";

    cout << editDistance(s1, s2) << "\n";

    return 0;
}