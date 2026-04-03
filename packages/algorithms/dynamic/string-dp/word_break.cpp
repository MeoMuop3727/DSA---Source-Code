#include <bits/stdc++.h>
#include "../grid-dp/tools.h"
using namespace std;

int wordBreak(const string &str, unordered_set<string> &wordDict) {
    int n = str.length();
    int maxLength = 0;

    vector<int> memo(n + 1);

    // Base case
    memo[0] = 1;

    // Find max length in wordDict
    // If the word we find over pass max length
    // This means that is wrong
    for (const auto &el : wordDict)
        maxLength = max(maxLength, (int)el.length());
    
    // Traversal
    for (int i = 1; i <= n; i++) 
        // We will reverse browsing
        // From i - 1 to max(0, and maxLenght)
        // This means, we just need to consider 4 chars instead of more chars
        for (int j = i - 1; j >= max(0, i - maxLength); j--) {
            string sub = str.substr(j, i);
            // If memo[j] == true
            // This means, the previous chars is valid
            // We can break them
            // And the word exists in wordDict
            // memo[i] = true, then we will break the loop
            if (memo[j] && wordDict.find(sub) != wordDict.end()) {
                memo[i] = 1;
                break;
            }
        }
    
    return memo[n];
}

int main() {
    string str = "catsandog";
    unordered_set<string> wordDict = {"cat", "sand", "and", "dog", "cats"};

    cout << wordBreak(str, wordDict) << "\n";

    return 0;
}