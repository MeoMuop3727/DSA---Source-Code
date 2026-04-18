#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    public:
        PriorityQueue(int max_size, bool build_max_heap)
            : max_size(max_size), build_max_heap(build_max_heap) {
                nums.resize(max_size);
            }

        void enqueue(int value) {
            if (nums.size() + 1 <= max_size) {
                nums.push_back(value);
                if (build_max_heap)
                    for (int i = nums.size() / 2 - 1; i >= 0; i--)
                        _max_heapify(nums, nums.size(), i);
                else
                    for (int i = nums.size() / 2 - 1; i >= 0; i--)
                        _min_heapify(nums, nums.size(), i);
            }
        }

        void dequeue() {
            swapElement(nums[0], nums[nums.size() - 1]);
            nums.pop_back();
            if (build_max_heap)
                for (int i = nums.size() / 2 - 1; i >= 0; i--)
                    _max_heapify(nums, nums.size(), i);
            else
                for (int i = nums.size() / 2 - 1; i >= 0; i--)
                    _min_heapify(nums, nums.size(), i);
        }

        void printer() {
            for (int i : nums) cout << i << " ";
        }
    private:
        vector<int> nums;
        int max_size;
        bool build_max_heap;


        void swapElement(int &a, int &b) {
            int temp = a;
            a = b; b = temp;
        }


        void _max_heapify(vector<int> &nums, int size, int index) {
            int pos_largest = index;
            int pos_left_child = 2 * index + 1;
            int pos_right_child = 2 * index + 2;


            if (pos_left_child < size
                && nums[pos_left_child] > nums[pos_largest]) pos_largest = pos_left_child;
            if (pos_right_child < size
                && nums[pos_right_child] > nums[pos_largest]) pos_largest = pos_right_child;


            if (pos_largest != index) {
                swapElement(nums[pos_largest], nums[index]);
                _max_heapify(nums, size, pos_largest);
            }
        }


        void _min_heapify(vector<int> &nums, int size, int index) {
            int pos_smallest = index;
            int pos_left_child = 2 * index + 1;
            int pos_right_child = 2 * index + 2;


            if (pos_left_child < size
                && nums[pos_left_child] < nums[pos_smallest]) pos_smallest = pos_left_child;
            if (pos_right_child < size
                && nums[pos_right_child] < nums[pos_smallest]) pos_smallest = pos_right_child;


            if (pos_smallest != index) {
                swapElement(nums[pos_smallest], nums[index]);
                _min_heapify(nums, size, pos_smallest);
            }
        }
};
