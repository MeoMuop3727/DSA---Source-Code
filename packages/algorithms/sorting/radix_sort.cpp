#include <iostream>
#include <vector>
#include <map>
using namespace std;


/*
    Define: Radix Sort is an sorting algorithm which does not use comparation to sort.
    It bases on each digit of number. We have two way to sort, LSD (Least Significant
    Digit) -> from right to left, MSD (Most Significant Digit) -> from left to right.


    Include:
        + exp, to identify the index of number in bins.
        + bins, a map to save number.


    Process:
        + 1, we will loop and classify elements in array into bins.
        + 2, we will loop all elements in bins and assign numbers into array.
        + 3, repeat that until the maximum / exp <= 0.


    Complexity:
        + Time: all case is O(d * (n + k)), with n is number of element in array, d is maximum
        and k is base.
        + Space: O(n + k)
*/


int find_max(vector<int> nums) {
    int result = 0;
    for (int el : nums)
        if (el > result) result = el;
    return result;
}


void radix_sort(vector<int> &nums, int exp = 1) {


    if (find_max(nums) / exp <= 0) return;


    map<int, vector<int>> bins = {
        {0, {}},
        {1, {}},
        {2, {}},
        {3, {}},
        {4, {}},
        {5, {}},
        {7, {}},
        {8, {}},
        {9, {}}
    };
    int index = 0;
    for (int el : nums) bins[(el / exp) % 10].push_back(el);
   
    for (auto el : bins) {
        for (int x : el.second) {
            nums[index] = x;
            index++;
        }
    }


    radix_sort(nums, exp * 10);
}


int main() {
    vector<int> nums = {9,2,4,5,7,1,3,0,6,8};
    radix_sort(nums);
    for (int el : nums) cout << el << " ";
    return 0;
}
