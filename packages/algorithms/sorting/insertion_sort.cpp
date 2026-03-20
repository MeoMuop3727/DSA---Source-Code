#include <iostream>
#include <vector>
using namespace std;


/*
    Define: Insertion Sort is an algorithm which will select the element in array
    and assign the index is fit with value.


    Include:
        + nums is a array.
        + key is a var which save the element which will be changed.
        + j is a index var used to compare to others.


    Process:
        + 1, we will build a loop to traversal each element in array.
        + 2, save the element need to compare as key. Create the index j with
        j = i - 1 to allude all elements previous.
        + 3, creating a loop to insert the key to the fit index (use insertion
        algoritm) with condition is "j >= 0 && key < nums[j]".


    Complexity:
        + Time:
            - Best case: O(n) when all elements were sorted.
                - The number of comparation: n
                - The number of permutation: 0
            - Average case: O(n^2) all elements is random.
                - The number of comparation: n * (n - 1) / 2
                - The number of permutation: basing on the data.
            - Worst case: O(n^2) all elements were sorted gradual decrease.
                - The number of comparation: n * (n - 1) / 2
                - The number of permutation: n * (n - 1) / 2
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


int main() {
    vector<int> nums = {9,2,4,5,7,1,3,0,6,8};
    insertion_sort(nums);
    for (int el : nums) cout << el << " ";
    return 0;
}
