#include <iostream>
#include <vector>
using namespace std;


/*
    Define: Interchange Sort is an algorithm which will sort array by changing the
    position of elements in array if they have a difference.


    Include: nums is a array


    Process:
        + 1, we will create two loops, with the first loop i = 0 and the second is
        j = i + 1, both of them is smaller than nums.size()
        + 2, we will loop with a condition:
            - Case 1: If we use, nums[i] > nums[j] ==> Gradually increasing.
            - Case 2: If we use, nums[i] < nums[j] ==> Gradually decreasing.


    Complexity:
        + Time:
            - Best case: O(n^2) all elements were sorted.
                - The number of comparation: n * (n - 1) / 2
                - The number of permutation: 0
            - Average case: O(n^2) all elements is random.
                - The number of comparation: n * (n - 1) / 2
                - The number of permutation: basing on the data.
            - Worst case: O(n^2) all elements were sorted gradual decrease.
                - The number of comparation: n * (n - 1) / 2
                - The number of permutation: n * (n - 1) / 2
        + Space: O(1)
*/


void interchange_sort(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++)
            if (nums[j] < nums[i]) swap(nums[i], nums[j]);
    }
}


int main() {
    vector<int> nums = {9,2,4,5,7,1,3,0,6,8};
    interchange_sort(nums);
    for (int el : nums) cout << el << " ";
    return 0;
}
