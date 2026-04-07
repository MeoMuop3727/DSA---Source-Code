#include <bits/stdc++.h>
#include "tools.h"
using namespace std;

int countNode(BinarySearchTree &bst) {
    int n = bst.get_nums_node();
    auto it  = bst.get_root();

    vector<int> memo(n); 
    
    // Base case
    memo[0] = 1;

    // DFS
    
}

int main() {
    vector<int> nums = {5,3,7,4,2,1,6,8,9};
    
    BinarySearchTree bst(nums);

    return 0;
}