#include <iostream>
#include <vector>
using namespace std;


/*
    Define: Heap Sort is an algorithm have the time complexity offten
    is O(n log n) in all cases thank to the binary tree structure, algorithm
    always maintains high performance and no need extra memory. But it does
    not stable.


    Include:
        + Heapify:
            - largest: is temporary variable to save the value at index.
            - pos_left_child: save the element is on the left, 2 * index + 1.
            - pos_right_child: save the element is on the right, 2 * index + 2.
        + Heap Sort.


    Process: having two ways to build heap, bottom-up and top-down. But we just
    forcus on bottom-up.
        + 1, we will build heapify. We will compare the value at largest, pos_left_child
        and pos_right_child to find the largest element.
        + 2, if the largest is different from index, we will transform them and build
        heap again.
            - Build max-heap: nums[pos_left_child] > nums[largest] and nums[pos_right_child] > nums[largest]
            ==> Gradually increasing.
            - Build min-heap: nums[pos_left_child] < nums[largest] and nums[pos_right_child] < nums[largest]
            ==> Gradually decreasinh.
        + 3, after building heap, we will sort the array from bottom to up by swappinh the element
        at 0 and i (with i = nums.size() - 1), then decline i by one level.


    Complexity:
        - The time to build heap: O(n).
        - The time to traversal elements: O(log n).
        + Time:
            - Best case: O(n log n) when all elements were sorted.
                - The number of comparation: n log n
                - The number of permutation: 0
            - Average case: O(n log n) all elements is random.
                - The number of comparation: n * (n - 1) / 2
                - The number of permutation: basing on the data.
            - Worst case: O(n log n) all elements were sorted gradual decrease.
                - The number of comparation: n * (n - 1) / 2
                - The number of permutation: n * (n - 1) / 2
        + Space: O(1)
*/


void heapify(vector<int> &nums, int size, int index) {
    int largest = index;
    int pos_left_child = 2 * index + 1;
    int pos_right_child = 2 * index + 2;


    if (pos_left_child < size &&
        nums[pos_left_child] > nums[largest]) largest = pos_left_child;
    if (pos_right_child < size &&
        nums[pos_right_child] > nums[largest]) largest = pos_right_child;
   
    if (largest != index) {
        swap(nums[largest], nums[index]);
        heapify(nums, size, largest);
    }
}


void heap_sort(vector<int> &nums, int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(nums, size, i);
   
    for (int i = size - 1; i >= 0; i--) {
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}


int main() {
    vector<int> nums = {9,2,4,5,7,1,3,0,6,8};
    heap_sort(nums, nums.size());
    for (int el : nums) cout << el << " ";
    return 0;
}
