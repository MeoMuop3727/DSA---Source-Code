#include <iostream>
#include <vector>
using namespace std;


/*
    Define: Linear Search is an algorithm which will traversal all elements in array
    and compare them to target, if the element compared to target is equal,
    return the index of these element. If we can not see any elements is equal
    target, return -1.


    Include:
        + An index variable i, starting with 0.
        + A size variable n, n = nums.size().
   
    Process:
        + 1, create an index i, start with 0.
        + 2, compare nums[i] to target:
            - If they are equal, return i.
            - If not, i++.
        + 3, if i is larger than size of array, return -1 if we can not see target.
   
    Complexity:
        + Time:
            - Best case: O(1) when the element which need to find is on the top.
            - Average case: O(n) when the element is random.
            - Worst case: O(n) when the element is on the bottom.
        + Space: O(1)
*/


int linear_search(vector<int> nums, int target) {
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] == target) return i;
    return -1;
}


int main() {
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    for (int el : nums) cout << linear_search(nums, el) << " ";
    return 0;
}
