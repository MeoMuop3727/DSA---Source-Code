#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


/*
    Define: Ternary Search is an algorithm which finds target on the sorted array. It is a combination
    between Binary Search and Jump Search.


    Include:
        + low and high are two variables which express the range of finding.
        + mid_1 and mid_3 are two vars which will divide the array.
            mid_1 = low + (high - low) / 3
            mid_3 = high - (high - low) / 3
   
    Process:
        + 1, we will divide the array into three parts:
            - Part 1: [low; mid_1)
            - Part 2: (mid_1; mid_3)
            - Part 3: (mid_3; high]
        + 2, we will compare target to each part. If:
            - nums[mid_1] > target, we will find in part 1.
            - nums[mid_3] < target, we will find in part 3.
            - Else, we will find in part 2.
        + 3, if we can not find target or low is higher high, return -1.
   
    Complexity:
        + Time:
            - Best case: O(1) when the target at mid_1 or mid_3.
            - Average case: O(log n) when the target is random.
            - Worst case: O(log n) when target is on the top or bottom or not exists.
        + Space: O(1).
*/


int ternary_search(vector<int> nums, int target, int low, int high) {
    if (low <= high) {
        int mid_1 = low + (high - low) / 3;
        int mid_3 = high - (high - low) / 3;


        if (nums[mid_1] == target) return mid_1;
        if (nums[mid_3] == target) return mid_3;


        if (nums[mid_1] > target)
            return ternary_search(nums, target, low, mid_1 - 1);
        else if (nums[mid_3] < target)
            return ternary_search(nums, target, mid_3 + 1, high);
        else
            return ternary_search(nums, target, mid_1 + 1, mid_3 - 1);
    }
    return -1;
}


int main() {
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    for (int el : nums) cout << ternary_search(nums, el, 0, nums.size() - 1) << " ";
    return 0;
}
