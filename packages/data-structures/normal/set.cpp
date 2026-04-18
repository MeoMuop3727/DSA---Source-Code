#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main() {
    // Create a set
    set<int> s = {1,2,2,3,3,5,4};
    // Traversal
    for (auto &x : s) cout << x << " ";

    // Create a multiset
    multiset<int> ms = {1,2,2,3,3,5,4};
    // Traversal
    for (auto &x : ms) cout << x << " ";

    // Create a unordered_set
    unordered_set<int> ms = {1,2,2,3,3,5,4};
    // Traversal
    for (auto &x : ms) cout << x << " ";
   
    // Create a unordered_multiset
    unordered_multiset<int> ms = {1,2,2,3,3,5,4};
    // Traversal
    for (auto &x : ms) cout << x << " ";
}