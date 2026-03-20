#include <iostream>
#include <vector>
using namespace std;


/*
    Define: Merge Sort is an algorithm which sorts array by Dividing and Conquering.
    It will divide the array until it just has one element and carry on sorting.


    Include:
        + Size of nums, including size of left array (size_left_nums), size of right array
        (size_right_array) and size of the array (size_nums).
        + Arrays, including left array (left_nums), right array (right_nums) and array (nums).
        + The indexes of elements in each array, including left (the index of left array),
        right (the index of right array) and index (the index of array).


    Process: We will divide into two proccesses:  
        + Divide array: Divide the array into two parts. Each part will divide contineuly until they are
            just one element in array.
        + Sort and merge arrays: We will build from bottom to up (bottom - up):
            - 1, we will compare the left element (element in left array) to the right element
            (element in right array), and sort them into array.
            - 2, we will repeat that until the array sorted.


    Complexity:
        + Time: Merge Sort always maintains stability with complexity is O(n log n)
        + Space: O(n), it bases on the size of array.
*/


void merge(vector<int> left_nums, vector<int> right_nums, vector<int> &nums) {
    int size_left_nums = left_nums.size();
    int size_right_nums = right_nums.size();


    int left = 0, right = 0, index = 0;


    while (left < size_left_nums && right < size_right_nums) {
        if (left_nums[left] < right_nums[right]) {
            nums[index] = left_nums[left];
            left++;
            index++;
        } else {
            nums[index] = right_nums[right];
            right++;
            index++;
        }
    }


    while (left < size_left_nums) {
        nums[index] = left_nums[left];
        left++;
        index++;
    }


    while (right < size_right_nums) {
        nums[index] = right_nums[right];
        right++;
        index++;
    }
}


void merge_sort(vector<int> &nums) {
    int size_nums = nums.size();


    if (size_nums <= 1) return;


    int size_left_nums = size_nums / 2;
    int size_right_nums = size_nums - size_left_nums;


    vector<int> left_nums; left_nums.resize(size_left_nums);
    vector<int> right_nums; right_nums.resize(size_right_nums);


    int left = 0, right = 0, index = 0;


    for (; left < size_left_nums; left++) {
        left_nums[left] = nums[index];
        index++;
    }
   
    for (; right < size_right_nums; right++) {
        right_nums[right] = nums[index];
        index++;
    }


    merge_sort(left_nums);
    merge_sort(right_nums);
    merge(left_nums, right_nums, nums);
}


int main() {
    vector<int> nums = {9,2,4,5,7,1,3,0,6,8,10};
    merge_sort(nums);
    for (int el : nums) cout << el << " ";
    return 0;
}
