#include <iostream>
#include <vector>
using namespace std;


/*
    Define: Selection Sort is an algorithm which will sort array by changing the
    position of elements in array if they have a difference. It will choose the
    smallest element to change with the element at the index i.


    Include:
        + nums is a array
        + pos_min is the index of smallest element


    Process:
        + 1, we will create two loops, with the first loop i = 0 and the second is
        j = i + 1.
        + 2, we will loop with a condition:
            - Case 1: If we use, nums[pos_min] > nums[j], update pos_min = j
            ==> Gradually increasing.
            - Case 2: If we use, nums[pos_min] < nums[j], update pos_min = j
            ==> Gradually decreasing.


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


void selection_sort(vector<int> &nums) {
    int pos_min = 0;


    for (int i = 0; i < nums.size(); i++) {
        pos_min = i;
        for (int j = i + 1; j < nums.size(); j++)
            if (nums[pos_min] > nums[j]) pos_min = j;
       
            if (pos_min != i) swap(nums[pos_min], nums[i]);
    }
}


int main() {
    vector<int> nums = {9,2,4,5,7,1,3,0,6,8};
    selection_sort(nums);
    for (int el : nums) cout << el << " ";
    return 0;
}
