#include <bits/stdc++.h>
using namespace std;

vector<pair<char,int>> rle(string str) {
    vector<pair<char,int>> result; // {character, freq}
    int cnt = 1; // Always equal 1, because of always existing one

    // Traversal all characters in str
    for (int i = 0; i < str.size(); i++) {
        // If the character at i and i + 1 is equal
        // Update cnt by 1
        if (str[i] == str[i + 1]) cnt++;
        // Else
        // Reset cnt = 1
        // Push {character, freq} to ans
        else {
            result.push_back({ str[i], cnt });
            cnt = 1;
        }
    }

    return result;
}

string decoding(vector<pair<char,int>> ans) {
    string result = "";

    // Traversal ans
    for (auto &e : ans) 
        for (int i = 0; i < e.second; i++) 
            result += e.first;
    
    return result;
}

int main() {
    string str = "abbcccddddfffffeeeeee";
    auto ans = rle(str);

    // Before compressing
    cout << "Before compressing: \t" << str << "\n";
    // After compressing
    cout << "After compressing: \t";
    for (auto &e : ans) {
        cout << e.second << e.first;
    }
    cout << "\n";
    // Decompressing coding
    cout << "Decompressing coding: \t" << decoding(ans) << "\n";
}