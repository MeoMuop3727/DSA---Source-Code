#include <iostream>
#include <vector>
using namespace std;


/*
    Define: Binary Search is an algorithm which will find elemnet on the sorted array.
    It will divide the array into two spaces, with the middle index, and compare the
    middle element of array to target.


    Include:
        + The middle variable will save index of middle element, it is calculated by:
            mid = left + (right - left) / 2
        + The left variable will show how element on the left was removed. Often starting with 0.
        + The right variable will show how element on the right was removed. Often starting with
        size of array.
        + The condition to stop the loop is "left > right".
   
    Process:
        + 1, we will calculate the value of mid: "mid = left + (right - left) / 2"
        + 2, we will compare the element at mid. If:
            - nums[mid] == target, return mid.
            - nums[mid] > target, we will narrow the gap to the right until the "mid - 1":
                right = mid - 1
            - nums[mid] < target, we will narrow the gap to the left until the "mid + 1":
                left = mid + 1
        + 3, return -1 if we can not find target.
   
    Complexity:
        + Time:
            - Best case: O(1) when the element is on the mid.
            - Average case: O(log n) when the element is random.
            - Worst case: O(log n) when the element is found with the size is 1.
        + Space: O(1)
*/


int binary_search(vector<int> nums, int target, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;


        if (nums[mid] == target) return mid;
        else if (nums[mid] < target)  
            return binary_search(nums, target, mid + 1, right);
        else if (nums[mid] > target)
            return binary_search(nums, target, left, mid - 1);
    }
    return -1;
}


int main() {
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    for (int el : nums) cout << binary_search(nums, el, 0, nums.size()) << " ";
    return 0;
}
