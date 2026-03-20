#include <iostream>
#include <vector>
using namespace std;


/*
    Define: Counting Sort is an algorithm which no need comparation with the
    overview time complexity is O(n + k). It is the most effective when "k = O(n)(O(n))",
    less effective when "k > O(n^2)".


    Include:
        + counts is an array save the number of repeating of elements.
        + nums is an array.


    Process:
        + 1, we will create an array which save the number of repeating of elements in
        array, the size of it bases on the largest element in array.
        + 2, traversal all elements in array and count them.
        + 3, traversal all elements in counts and replace all elements in array by index i.


    Complexity:
        + Time: three case is O(n + k) because Counting Sort operate by counting
        the number of repeating of element in array. As a result, the complexity does not
        change thought the data was sorted or mess. The best case is k <= nums.size()
        with the complexity is O(n). The worst case is k too large nums.size().
        + Space: O(k) or O(n + k)
*/


int largest(vector<int> nums) {
    int largest_element = 0;
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] > largest_element) largest_element = nums[i];
    return largest_element;
}


void counting_sort(vector<int> &nums) {
    int index = 0;
    vector<int> counts; counts.resize(largest(nums) + 1);


    for (int el : nums) counts[el] += 1;


    for (int i = 0; i < counts.size(); i++) {
        while (counts[i] > 0) {
            nums[index] = i;
            counts[i]--;
            index++;
        }
    }
}


int main() {
    vector<int> nums = {9,2,4,5,7,1,3,0,6,8};
    counting_sort(nums);
    for (int el : nums) cout << el << " ";
    return 0;
}
