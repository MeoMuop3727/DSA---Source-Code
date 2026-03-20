#include <iostream>
#include <vector>
using namespace std;


/*
    Define: Shell Sort is renovational Insertion Sort. But, we do not compare between
    adjacent elemenets, we will use gap to compare and gradually decrease gap.


    Include:
        + gap is a gap between two element. Often starting with nums.size() / 2.
        + nums is array.


    Process:
        + 1, we will loop and swap element with gap if they have inversion.
        + 2, decrease gap by one level (or use anthoer way to decrease gap).
        + 3, we will use Insertion Sort to sort for the last time when gap <= 1.


    Comlexity:
        + Time:
            - Best case: O(n log n), when the array have a good stucture for gap which
            will help decrease number of comperation and swap.
            - Average case: O(n^1.25) to O(n^1.5), complete basing on the gap.
            - Worst case: O(n^2) when the gap is less effective.
        + Space: O(1)
*/


void insertion_sort(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        int key = nums[i];
        int j = i - 1;


        while (j >= 0 && key < nums[j]) {
            nums[j + 1] = nums[j];
            j--;
        }


        nums[j + 1] = key;
    }
}


void shell_sort(vector<int> &nums, int gap) {
    if (gap <= 1) {
        insertion_sort(nums);
        return;
    }


    for (int i = 0; i + gap < nums.size(); i++)
        if (nums[i] > nums[i + gap]) swap(nums[i], nums[i + gap]);
   
    shell_sort(nums, gap - 1);
}


int main() {
    vector<int> nums = {9,2,4,5,7,1,3,0,6,8};
    shell_sort(nums, nums.size() / 2);
    for (int el : nums) cout << el << " ";
    return 0;
}
