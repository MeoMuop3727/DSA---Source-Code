#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int fib(int n) {
    // Create fibonacci number
    if (n <= 1) return 1;
    return fib(n - 1) + fib(n - 2);
}


vector<int> fib_arr(int size_num) {
    // Create fibonacci array: [1,1,2,3,5,8,...] from size of nums
    vector<int> result; result.resize(size_num);
    for (int i = 0; i < size_num; i++) result[i] = fib(i);
    return result;
}


int fib_search(vector<int> nums, int target) {
    /*
        Fibbonacci Search is an algorithm which will find a target on sorted array.
        This algorithm will use fibonacci to divide space to find target, instead of dual like
        Binary Search. In this algorithm will include:
            + fibM: The variable will set up the area to find target.
            + fibM1: The var will set up the rliemaining space and the condition to stop the loop.
            + fibM2: The var will set up the index to compare.
            + offset: The var saves the last index which is not target's index, also show how many elements
            removed on the left, start with -1.
            + i: The index to compare with target, i = min(offset + fibM2, n - 1), with n is size of nums


        Processing:
            + 1, we will find the the fibonacci which is larger or equal n and save it into fibM.
            Then we will find two fibonacci with condition: fibM = fibM1 + fibM2.
            + 2, we will loop with condition is "fibM1 > 1".
            + 3, we will compare the element at i and target. If:
                - target > nums[i]: we will remove all elements are on left until the index i:
                    fibM = fibM1; fibM1 = fibM2; fibM2 = fibM - fibM1; offset = i
                - target < nums[i]: we will remove all elements are on right:
                    fibM = fibM2; fibM1 -= fibM2; fibM2 = fibM - fibM1;
            + 4, after the loop if we do not see the target, we will compare target with the element has index is "offset + 1":
            if fibM1 == 1. If true we will return "offset + 1".
            + 5, if we do not find target, return -1.
       
        Explain:
            + 1, why we must have 3 elements, fibM, fibM1 and fibM2? Because according to fibonacci principle:
            F(n) = F(n - 1) + F(n - 2), we can use this to calculate instead of use fib function again.
            + 2, why we must double decrease if target > nums[i]? Because the index i skewed to one side left, this makes the
            size of left is smaller than right. Or: |----fibM2----| i |--------fibM1---------|. Because the size of left is too
            small, we can remove with a lot of elements. By contrast, if target < nums[i], the size is too big so we must remove
            less than left to the size is not too small to enough space to compare.
    */
    int fibM, fibM1, fibM2, offset = -1, n = nums.size();
    vector<int> array_fib = fib_arr(n);


    for (int i = 0; i < array_fib.size(); i++) {
        if (array_fib[i] >= n) {
            fibM = array_fib[i];
            fibM1 = array_fib[i - 1];
            fibM2 = array_fib[i - 2];
            break;
        }
    }


    while (fibM1 > 1) {
        int i = min(offset + fibM2, n - 1);


        if (nums[i] == target) return i;
        else if (nums[i] > target) {
            fibM = fibM2;
            fibM1 -= fibM2;
            fibM2 = fibM - fibM1;
        } else if (nums[i] < target) {
            fibM = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i;
        }
    }


    if (fibM1 == 1 && nums[offset + 1] == target) return offset + 1;
    return -1;
}


int main() {
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    for (int i : nums) cout << fib_search(nums, i) << " ";
    return 0;
}
