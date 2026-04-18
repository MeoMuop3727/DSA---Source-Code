#pragma once
#include <iostream>
#include <queue>

namespace trees {
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
    template<typename T>
    void printTree(T *root) {
        std::queue<T*> q;
        q.push(root);

        while (!q.empty()) {
            T *current = q.front(); q.pop();
            std::cout << current->value << " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

    // Function search a value in binary search tree
    // Return node
    template<typename T>
    T *searchTree(T *root, int value) {
        if (!root) return nullptr;

        if (value < root->value)
            return searchTree(root->left, value);
        else if (value > root->value)
            return searchTree(root->right, value);
        else return root;

        return nullptr;
    }
}