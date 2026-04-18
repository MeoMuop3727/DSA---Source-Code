#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    /*
        ==============
            QUEUE
        ==============
    */
    // Create empty queue
    queue<int> q;
    // Push value to queue
    q.push(0); // Empty --> 0
    q.push(1); // 0 --> 0 1
    q.push(2); // 0 1 --> 0 1 2
    // Get the first element
    cout << q.front() << "\n"; // Get 0
    // Delete the top element
    q.pop(); // Delete 0   
}