#include <bits/stdc++.h>
#include "../grid-dp/tools.h"
using namespace std;

int wordBreak(const string &str, unordered_set<string> &wordDict) {
    int n = str.size();
    vector<int> memo(n + 1);

    // Base case
    memo[0] = 1;

    

    forEach(memo);
    return memo[n];
}

int main() {
    string str = "leetcode";
    unordered_set<string> wordDict = {"leet", "code"};

    cout << wordBreak(str, wordDict) << "\n";

    return 0;
}