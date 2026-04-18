#include <bits/stdc++.h>
using namespace std;

// Node
class Node {
    public:
        int value; // Value of node
        Node *next; // The next node, defaault is nullptr
        Node(int value) : value(value), next(nullptr) {}
};

// Single Linked List
class SingleLinkedList {
    private:
        Node *head = nullptr; // Save the address of first element
        Node *tail = nullptr; // Save the address of last element
        size_t size = 0; // Size of single linked list
    
    public:
        // Return the address of head
        Node *get_head() { return head; }
        
        // Return the address of tail
        Node *get_tail() { return tail; }

        // Return size of single linked list
        size_t get_size() { return size; }

        // Function builds single linked list from array
        // Time complexity: O(n)
        // Space complexity: O(1)
        void append_range(const vector<int> &nums) {
            for (auto &element : nums) {
                Node *newNode = new Node(element);
                
                // If head is not existed
                // Assign newNode into new head
                if (!head) head = newNode;

                // Else
                // Add end it
                else {
                    auto it = head;
                    while (it->next) it = it->next;
                    it->next = newNode;
                }

                // Update tail
                tail = newNode;
                size++;
            }
        }

        // Function print single linked list
        // Time complexity: O(n)
        // Space complexity: O(1)
        void print() {
            auto it = head;
            while (it) {
                cout << it->value;
                if (it->next) cout << " --> ";
                it = it->next;
            }
            cout << "\n";
        }
        
        // Function add new node at the top
        // Time complexity: O(1)
        // Space complexity: O(1)
        void push_front(int value) {
            Node *newNode = new Node(value);

            // If the head is not existed
            if (!head) head = newNode;
            
            // Else
            else {
                newNode->next = head;
                head = newNode;
            }

            // If the tail is not existed
            if (!tail) tail = newNode;

            size++;
        }

        // Function add new node at the middle
        // Time complexity: O(n)
        // Space complexity: O(1)
        void push_middle(int value) {
            Node *newNode = new Node(value);

            // If head is not existed
            if (!head) head = newNode;
            
            // Else
            else {
                auto it = head;
                for (int i = 0; i < (int)size / 2; i++)
                    it = it->next;
                auto temp = it->next;
                it->next = newNode;
                newNode->next = temp;
            }
            size++;
        }

        // Function add new node at the bottom
        // Time complexity: O(1)
        // Space complexity: O(1)
        void push_back(int value) {
            Node *newNode = new Node(value);

            // If head is not existed
            if (!head) head = newNode;
            
            // If tail is not existed
            if (!tail) tail = newNode;
            else {
                tail->next = newNode;
                tail = newNode;
            }
            size++;
        }

        // Function delete a node at the top
        // Time complexity: O(1)
        // Space complexity: O(1)
        void pop_front() {
            // If the head is not existed, don't do anything
            if (!head) return;

            // If only one node
            if (head == tail) {
                delete head;
                head = tail = nullptr;
                size--;
                return;
            }

            auto temp = head; // Assign old head with temporary var
            head = head->next; // Update new head
            delete temp; // Delete old head to avoid stack overflow
            size--;
        }

        // Function delete a node at the middle
        // Time complexity: O(n)
        // Space complexity: O(1)
        void pop_middle() {
            // If the head is not existed, don't do anything
            if (!head) return;

            // Only one node
            if (head == tail) {
                delete head;
                head = tail = nullptr;
                size--;
                return;
            } 

            auto it = head;
            for (int i = 0; i < (int)size / 2 - 1; i++) 
                // Check if the next of next node is null
                // If it is not
                // Go continuely
                if (it->next->next) it = it->next;

            auto temp = it->next; // The node need to delete
            it->next = it->next->next; // Make a connection
            delete temp;
            size--;
        }

        // Function delete a node at the bottom
        // Time complexity: O(n)
        // Space complexity: O(1)
        void pop_back() {
            // If head or tail is not existed
            if (!head || !tail) return; 

            // Only one node
            if (head == tail) {
                delete head;
                head = tail = nullptr;
                size--;
                return;
            }  

            auto it = head;
            // Loop until we find the node front tail
            while (it->next != tail) it = it->next;
            delete tail;
            tail = it; // Update new tail
            tail->next = nullptr; // Update new tail
            size--;
        }

        // Function find a node according to value and return bool
        // + 0 is not found
        // + 1 is found
        // Time complexity: O(n)
        // Space complexity: O(1)
        bool count(int value) {
            auto it = head;
            
            // If head is not existed
            // Return false
            if (!head) return false;

            while (it) {
                // If it is found
                // Return true
                if (it->value == value) return true;
                else it = it->next;
            }

            // If can not find
            // Return false
            return false;
        }
};

int main() {
    vector<int> nums = {0,1,2,3,4,5};

    SingleLinkedList SLL; 
    SLL.append_range(nums);
    SLL.print();

    return 0;
}
