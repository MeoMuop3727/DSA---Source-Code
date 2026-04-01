#include <bits/stdc++.h>
#include "../grid-dp/tools.h"
using namespace std;

int lsc(const string &s1, const string &s2) {
    int n = s1.size(); // Column
    int m = s2.size(); // Row

    matrix memo(m + 1, vector<int>(n + 1, 0));

    // Traversal all elements
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            // If the char of s1 is equal s2's char
            // This means they are the same
            // Update the lenght by 1
            if (s1[j - 1] == s2[i - 1]) 
                memo[i][j] = memo[i - 1][j - 1] + 1;
            
            // Else
            // Choose the maximum in two previous cases
            else   
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
        }
    
    return memo[m][n];
}

int main() {
    string s1 = "abcd";
    string s2 = "bd";

    cout << lsc(s1, s2) << "\n";

    return 0;
}