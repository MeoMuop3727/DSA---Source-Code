#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


/*
    Define: Interpolation Search is an algorithm like Binary Search, but it finds target
    base on the contribution of values in array. As a result, we can forecast the index of
    target.


    Include:
        + low and high are two variables which express the range of finding.
        + mid is a position which was forecasted.
   
    Process:
        + 1, we will divide the array into two parts by caculating mid:
            mid = low + (target - nums[low]) * (high - low) / (nums[high] - nums[low])
        + 2, we will compare mid to target. If:
            - nums[mid] == target, return mid.
            - nums[mid] > target, high = mid - 1
            - nums[mid] < target, low = mid + 1;
        + 3, if we can not find target or low is higher high, return -1.
   
    Complexity:
        + Time:
            - Best case: O(1) when the target at mid or near the forecasted position.
            - Average case: O(log(log n)) when the values in the array is evenly contributed.
            - Worst case: O(n) when the array is not evenly contributed.
        + Space: O(1).
*/


int interpolation_search(vector<int> nums, int target, int low, int high) {
    if (low <= high) {
        int mid = low + (target - nums[low]) * (high - low) / (nums[high] - nums[low]);


        if (nums[mid] == target) return mid;
        else if (nums[mid] > target)
            return interpolation_search(nums, target, low, mid - 1);
        else if (nums[mid] < target)
            return interpolation_search(nums, target, mid + 1, high);
    }
    return -1;
}


int main() {
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    for (int el : nums) cout << interpolation_search(nums, el, 0, nums.size() - 1) << " ";
    return 0;
}
