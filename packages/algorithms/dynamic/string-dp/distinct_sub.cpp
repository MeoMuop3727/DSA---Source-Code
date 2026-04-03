#include <bits/stdc++.h>
#include "../grid-dp/tools.h"
using namespace std;

int distinctSub(const string &str, const string &sub) {
    int n = sub.size(); // Column
    int m = str.size(); // Row

    matrix memo(m + 1, vector<int>(n + 1, 0));

    // Base case
    memo[0][0] = 1;
    
    // memo[i][0] = 1, this mean t = "", always has one way, don't choose
    for (int i = 1; i <= m; i++) memo[i][0] = 1;

    // memo[0][j] = 0, this mean s = "", no way to choose
    for (int j = 1; j <= n; j++) memo[0][j] = 0;

    // Traversal
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            // If the char in str[i] != sub[j]
            // This mean we cannot match them together
            // We must skip it and use i - 1 chars in s to create j - 1 t
            // For example, 
            // s = "rab", t = "rb", at i = 2, j = 2, this mean s[1] = 'a' != t[1] = 'b'
            // We can not use "ra" to create "rb", therefore, skip 'a', we only have "r" --> "rb"
            // And, we cannot create "rb" from "r", so memo[2][2] = 0
            if (str[i - 1] != sub[j - 1])
                memo[i][j] = memo[i - 1][j];
            
            // Else
            // We have two ways
            // Choose and not choose
            // Because the char is not important, the previous char may be the same as the current char
            // With not choose char, they are same as below
            // And choose char. we come back the previous problem
            // For example,
            // s = "ra", t = "ra", at i = j = 2, s[1] == t[1] == 'a'
            // After choosing, s = t = "r", we just one way to create 's' --> 's'
            // As a result, memo[2][2] = 1
            // Total two ways are the result
            else   
                memo[i][j] = memo[i - 1][j] + memo[i - 1][j - 1];
        }

    return memo[m][n];
}

int main() {
    string str = "rabb";
    string temp = "rab";

    cout << distinctSub(str, temp) << "\n";

    return 0;
}