#include <bits/stdc++.h>
#include "../grid-dp/tools.h"
using namespace std;

int lsc(const string &s1, const string &s2) {
    int n = s1.size(); // Column
    int m = s2.size(); // Row

    matrix memo(m + 1, vector<int>(n + 1, 0));

    int maxLength = 0;

    // Traversal all elements
    for (int i = 1; i <= m; i++) 
        for (int j = 1; j <= n; j++) {
            // If the char of s1 is different from s2's char
            // memo[i][j] == 0,
            // This means, we will pass it
            if (s1[j - 1] != s2[i - 1]) continue;

            // Else
            // Update the lenght by 1
            memo[i][j] = memo[i - 1][j - 1] + 1;

            // Because the maximum is not at memo[m][n]
            // We need a temp var to save the max
            maxLength = max(maxLength, memo[i][j]);
        }
    
    return maxLength;
}

int main() {
    string s1 = "abcd";
    string s2 = "acdf";

    cout << lsc(s1, s2) << "\n";

    return 0;
}