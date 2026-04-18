#include <iostream>
#include <vector>
using namespace std;

class Deque {
    public:
        Deque(int max_size) : max_size(max_size) {
            nums.resize(max_size);
        }

        void insertFront(int value) {
            // This function will be insert a new element into deque
            /*
                First, this function will check if the deque is full. If yet:
                    + front == -1, we will assign front and rear by 0
                    + front == 0, we will assign front by max_size - 1, we will
                insert from end to start
                    + else, we the front will be decreased by one until it by one
            
                And, why must we assign rear by 0? Because two reasons:
                    + First, we assign rear = 0 to can loop and printer element by printer()
                    + Second, when we assign rear = 0, we can avoid the error of the codition
                of isFull(), especially when front = 0 && rear = -1, this is mean:
                front = rear + 1 = -1 + 1 = = 0 and this is true, the deque cannot add any elements
            */
            if (!isFull()) {
                if (front == -1) front = 0, rear = 0;
                else if (front == 0) front = max_size - 1;
                else front--;
                nums[front] = value;
            }
        }

        void insertRear(int value) {
            // This function will insert a new value into deque
            /*
                The operation of function:
                First, this function will check if the deque is full. If yet:
                    + front == -1 => front = rear = 0
                    + rear == max_size - 1 => rear = 0. This mean the rear will be reseted
                    + else, rear will increase by 1 until it's satisfied second condition
                And, also insertFront(), the reason why must we use the first condition is same
                as
            */
            if (!isFull()) {
                if (front == -1) front = 0, rear = 0;
                else if (rear == max_size - 1) rear = 0;
                else rear++;
                nums[rear] = value;
            }
        }

        void popFront() {
            // This function will delete a element of deque
            /*
                This function will check if the deque is empty. If yet:
                    + front == rear (this mean is only one element) => front = rear = -1
                    + front == max_size - 1 => front = 0. Deleting an element at end
                    + else, front will increase by 1 until it is sactisfied the second condition
            */
            if (!isEmpty()) {
                if (front == rear) front = -1, rear = -1;
                else if (front == max_size - 1) front = 0;
                else front++;
            }
        }

        void popRear() {
            // This function will delete a element of deque
            /* This is same as popFront() */
            if (!isEmpty()) {
                if (front == rear) front = -1, rear = -1;
                else if (rear == 0) rear = max_size - 1;
                else rear--;
            }
        }

        void printer() {
            if (front <= rear) {
                for (int i = front; i <= rear; i++) printf("[%d] ", nums[i]);
            } else {
                for (int i = 0; i <= rear; i++) printf("[%d] ", nums[i]);
                for (int i = front; i < max_size; i++) printf("[%d] ", nums[i]);
            }
        }
    private:
        int max_size, front = -1, rear = -1;
        vector<int> nums;

        bool isFull() {
            return ((front == 0 && rear == max_size - 1) || (front == rear + 1));
        }

        bool isEmpty() {
            return (front == -1);
        }
};
