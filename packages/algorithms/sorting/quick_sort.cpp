#include <iostream>
#include <vector>
using namespace std;


/*
    Define: Quick Sort is an algorithm which will sort the array by divide it into
    each small array and sort them (divide and conquer).


    Include:
        + Start and end are two index which is a range to sort.
        + Pivot is an index of element which we used it likes an marker.


    Process:
        + 1, we will find the element is fit with the middle position, and then dividing
        array into two part.
        + 2, repeat that again until the array sorted.


    Complexity:
        + Time:
            - Best: O(n log n) when the pivot always divides array into two parts are the same.
            - Average: O(n log n), this is random.
            - Worst: O(n^2) when the pivot is always smallest or largest.
        + Space:
            - Best and Aveage: O(log n).
            - Worst: O(n)
*/


int partition(vector<int> &nums, int start, int end) {
    int j = start - 1;


    for (int i = start; i <= end - 1; i++) {
        if (nums[i] < nums[end]) {
            j++;
            swap(nums[i], nums[j]);
        }
    }


    j++;
    swap(nums[j], nums[end]);


    return j;
}


void quick_sort(vector<int> &nums, int start, int end) {
    if (start >= end) return;


    int pivot = partition(nums, start, end);


    quick_sort(nums, pivot + 1, end);
    quick_sort(nums, start, pivot - 1);
}


int main() {
    vector<int> nums = {9,2,4,5,7,1,3,0,6,8};
    quick_sort(nums, 0, nums.size() - 1);
    for (int el : nums) cout << el << " ";
    return 0;
}
