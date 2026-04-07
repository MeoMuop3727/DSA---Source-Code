#pragma once

#include <iostream>
#include <vector>

class Node {
    public:
        int value;
        Node *left, *right;
        Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
    private:
        std::vector<int> nums;
        Node *root = nullptr;

        Node *buildTree(const int &value, Node *it) {
            if (!it) it = new Node(value);

            else {
                if (value > it->value)
                    it->right = buildTree(value, it->right);
                else it->left = buildTree(value, it->left);
            }

            return it;
        }

    public:
        BinarySearchTree(std::vector<int> &nums) : nums(nums) {
            for (int &el : nums) root = buildTree(el, root);
        }

        Node *get_root() { return root; }

        int get_nums_node() { return (int)nums.size(); }
};