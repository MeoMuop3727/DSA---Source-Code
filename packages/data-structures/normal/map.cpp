#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    // Map
    vector<int> v = {0,1,2,3,4}; // To save key - value of mp
    map<int, int> mp; // Create a map
    for (int &e : v) mp[e] = e;
    // Print map
    for (const auto &[key, value] : mp)
        printf("{%d, %d}\n", key, value);

    // Unordered map
    unordered_map<int, int> un_mp; // Create a unordered map
    for (int &e : v) un_mp[e] = e;
    // Print map
    for (const auto &[key, value] : un_mp)
        printf("{%d, %d}\n", key, value);

    // Multimap
    multimap<int, int> mul_mp = {
        {1, 0}, {1, 2}, {2, 2}
    };
    auto range = mul_mp.equal_range(1); // Get elements with key = 1
    // Traversal
    // it = range.first is mean keys = 1
    // it != range.second is mean keys != 1
    // If we traversal all key = 1 completely, we will stop
    for (auto it = range.first; it != range.second; it++)
        cout << it->second << "\n";
}