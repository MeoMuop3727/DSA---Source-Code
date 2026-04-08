#pragma once
#include <iostream>
#include <queue>

/**
    * @brief        Node of tree
    * @param value  Value of node
    * @param left   Address of left node
    * @param right  Address of right node 
*/
class Node {
    public:
        int value;
        Node *left, *right;
        Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

// Function prints the tree which uses BFS
void printTree(Node *root) {
    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *current = q.front(); q.pop();
        std::cout << current->value << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}