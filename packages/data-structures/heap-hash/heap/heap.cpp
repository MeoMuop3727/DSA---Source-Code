#include <iostream>
#include <vector>
using namespace std;

class Heap {
    public:
        Heap(vector<int> arr, bool __build_max_heap) 
            : nums(arr), build_max_heap(__build_max_heap) {
            // We will build directly a max or min - heap when we enter a array in here
            // The parameter of build_max_heap if true build a max, build a min
            if (build_max_heap) 
                for (int i = nums.size() / 2 - 1; i >= 0; i--) 
                    _max_heapify(nums, i);
            else 
                for (int i = nums.size() / 2 - 1; i >= 0; i--) 
                    _min_heapify(nums, i);
        }

        void printer() {
            // Just use to printer all elements in a heap
            for (int i : nums) printf("[%d] ", i);
        }

        int peek() {
            /*
                This function will always return nums[0] because with max - heap the first element is
                always the maximum and that also is true for min - heap (minimum)
            */
            return nums[0];
        }

        int extract() {
            /*
                This function is same as peek(), but it will delete the maximum (max - heap) or
                minimum (min - heap) in the heap
            */
            int temp = nums[0];
            deleteElement(nums[0]);
            return temp;
        }

        void insertElement(int value) {
            // This function will add a new element in the array
            /*
                We do not need insert start - end - mid, when just need to insert it, in here
                we just ask about the insert end. After inserting, we will rebuild the array by sorting it
                according to algorithm max or min - heap
            */
            nums.push_back(value);
            // Rebuild the heap
            if (build_max_heap) 
                for (int i = nums.size() / 2 - 1; i >= 0; i--) 
                    _max_heapify(nums, i);
            else 
                for (int i = nums.size() / 2 - 1; i >= 0; i--) 
                    _min_heapify(nums, i);
        }

        void deleteElement(int value, int index = 0) {
            // This function will delete an element in the array
            /*
                We can build a delete function element at start - end - mid, but now we just focus on
                deleting the elements with the values is equal the inputing value
            */
            /*
                In here, we will have two parameters, the value wanting to delete and index, default the value
                of the index is equal zero. First, we will check the index if it is in arrange [0, nums.size() - 1].
                If that is true, we will check nums[index] == value (*). Second, if (*) is true, we will place
                it to the end of the array and use pop_back() to remove it. Finally, we will rebuild it again.
                Also, if (*) is false, we will do all those again until we can find the element we want to delete  
            */
            if (index <= nums.size()) {
                if (nums[index] == value) {
                    swapElement(nums[index], nums[nums.size() - 1]);
                    nums.pop_back();
                    // Rebuild the heap
                    if (build_max_heap) 
                        for (int i = nums.size() / 2 - 1; i >= 0; i--) 
                            _max_heapify(nums, i);
                    else 
                            for (int i = nums.size() / 2 - 1; i >= 0; i--) 
                        _min_heapify(nums, i);
                }
                deleteElement(value, 2 * index + 1);
                deleteElement(value, 2 * index + 2);
            }
        }

        bool searchElement(int value, int index = 0) {
            // This function will return true if your element you want to find existing
            /*
                We will have two parameters, first is value and then is index = 0.
                Same with delete function, if index is greater than nums.size(), we will return false.
                If the nums[index] == value we will return true.
                Also, if index is smaller than nums.size() and we cannot find any element which is equal
                value, we will do all those again until we can find it.
            */
            if (index > nums.size()) return false;
            if (nums[index] == value) return true;
            return  searchElement(value, 2 * index + 1) || 
                    searchElement(value, 2 * index + 2);
        }
    private:
        vector<int> nums;
        bool build_max_heap;

        void swapElement(int &a, int &b) {
            // Just use to transform between two values
            int temp = a;
            a = b; b = temp;
        }

        void _max_heapify(vector<int> &nums, int index) {
            // This function will build a max - heap
            int pos_largest = index;
            int pos_left_child = 2 * index + 1;
            int pos_right_child = 2 * index + 2;

            if (pos_left_child < nums.size()
                && nums[pos_left_child] > nums[pos_largest]) 
                    pos_largest = pos_left_child;
            if (pos_right_child < nums.size()
                && nums[pos_right_child] > nums[pos_largest]) 
                    pos_largest = pos_right_child;

            if (pos_largest != index) {
                swapElement(nums[pos_largest], nums[index]);
                _max_heapify(nums, pos_largest);
            }
        }

        void _min_heapify(vector<int> &nums, int index) {
            // This function will build a min - heap
            int pos_smallest = index;
            int pos_left_child = 2 * index + 1;
            int pos_right_child = 2 * index + 2;

            if (pos_left_child < nums.size()
                && nums[pos_left_child] < nums[pos_smallest]) 
                    pos_smallest = pos_left_child;
            if (pos_right_child < nums.size()
                && nums[pos_right_child] < nums[pos_smallest]) 
                    pos_smallest = pos_right_child;

            if (pos_smallest != index) {
                swapElement(nums[pos_smallest], nums[index]);
                _min_heapify(nums, pos_smallest);
            }
        }
};


int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    Heap heap = Heap(nums, true);
    heap.printer();
    return 0;
}
