#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


/*
    Define: Exponential Search is an algorithm which will find the target in a sorted array
    with range [prev; lenght).


    Include:
        + prev: is a variable which saves the number of element is removed, start with 0.
        + lenght: is a variable which saves the range contains target (if exists),
        start with 1.
   
    Process:
        + 1, we will find the range which contains target by repeatting, if nums[min(lenght, nums.size()) - 1]
        smaller than target, we will update:
            - prev = lenght
            - lenght = lenght * 2
        + 2, if nums[min(lenght, nums.size()) - 1] is larger than or equal target, we will loop in
        [prev; min(lenght, nums.size())] to find target. If find return the index.
        + 3, if we can not find the target, return -1.
   
    Complexity:
        + Time:
            - Best case: O(1) when the target is on the top.
            - Average case: O(log i) when the target is random, with i is index of target.
            - Worst case: O(log n) when target is on the bottom or not exists.
        + Space: O(1).
*/


int exponential_search(vector<int> nums, int target, int prev, int lenght) {
    int n = nums.size();


    if (nums[min(lenght, n) - 1] < target)
        return exponential_search(nums, target, lenght, lenght * 2);
   
    while (prev < min(lenght, n)) {
        if (nums[prev] == target) return prev;
        prev++;
    }


    return -1;
}


int main() {
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    for (int el : nums) cout << exponential_search(nums, el, 0, 1) << " ";
    return 0;
}
