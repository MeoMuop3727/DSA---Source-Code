#include <iostream>
using namespace std;

class Node {
    public:
        Node(int value) : value(value), left(nullptr), right(nullptr) {}
        Node* left;
        Node* right;
        int value;
};
int main() {
    Node* root = new Node(0); // Creating a root
    // Creating nodes
    Node* node1 = new Node(1); Node* node2 = new Node(2);
    Node* node3 = new Node(3); Node* node4 = new Node(4);
    Node* node5 = new Node(5); Node* node6 = new Node(6);
    // Connect nodes together
    // You can use debug to see clearly
    root -> left = node1; root -> right = node2;
    node1 -> left = node3; node1 -> right = node4;
    node2 -> left = node5; node2 -> right = node6;

    return 0;
}
