#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &nums, int size, int index) {
    int largest = index; // The index of largest element
    int left = 2 * index + 1; // The index of left element
    int right = 2 * index + 2; // The index of right element

    // If the index is still in suitable range
    // And the nums[left] or nums[right] is larger than current
    // Update largest according to the index of largest element (build max-heap)
    // By contrast, choose the minimal element, then we will have miin-heap
    if (left < size && nums[left] > nums[largest]) largest = left;
    if (right < size && nums[right] > nums[largest]) largest = right;

    // If the index is different from largest
    // This means the largest element was updated
    // Swap them
    if (largest != index) {
        swap(nums[index], nums[largest]);
        helper(nums, size, largest);
    }
}
vector<int> heapify(const vector<int> &nums) {
    int size = nums.size(); // Size of array
    vector<int> heap_tree = nums; // Copy array
    
    // Loop from the middle of array to 0
    for (int i = size / 2 - 1; i >= 0; i--)
        helper(heap_tree, size, i);

    return heap_tree;
}

int main() {
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    vector<int> heap_tree = heapify(nums);
    for (auto &e : heap_tree) cout << e << " ";
    return 0;
}