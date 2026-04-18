#include <iostream>
#include <vector>
using namespace std;

class CircularQueue {
    public:
        CircularQueue(int max_size) : max_size(max_size) {
            nums.resize(max_size);
        }

        void enqueue(int value) {
            /*
                Also dequeue(), because Circular Queue has method the loop,
                so rear and front must have auto reset
            */
            if ((rear + 1) % max_size != front) {
                if (front == -1) front = 0;
                rear = (rear + 1) % max_size;
                nums[rear] = value;
            }
        }

        void dequeue() {
            /*
                "front = (front + 1) % max_size"
                We use this method to reset front to zero if we need to.
                This means if delete an element is Queue, the front will be != 0, also
                the rear will be != max_size because it was updated to add a new element
                at index according to: "rear = (rear + 1) % max_size".
                All in all, because Circular Queue has method the loop, so rear and front must
                have auto reset
            */
            if (front == rear) {front = -1; rear = -1;}
            else front = (front + 1) % max_size;
        }

        void printer() {
            /*
                Note: [element] -> the element was removed
                Differences between printer() of Queue and printer() of Circular Queue
                are:
                    + [1] 2 3 4 -> this of Queue
                    + [1] 2 3 4
                    1 [2] 2 4 -> both of them of Circular Queue
                ==> So this reason why printer() of Circular Queue need two conditions
                to can loop and print
            */
            if (front <= rear) {
                for (int i = front; i <= rear; i++) {
                    cout << "[" << nums[i] << "] ";
                }
            } else {
                for (int i = 0; i <= rear; i++) {
                    cout << "[" << nums[i] << "] ";
                }
                for (int i = front; i < max_size; i++) {
                    cout << "[" << nums[i] << "] ";
                }
            }
        }
    private:
        vector<int> nums;
        int max_size;
        int front = -1, rear = -1;
};
