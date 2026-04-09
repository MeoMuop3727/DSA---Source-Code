#include <bits/stdc++.h>
#include "../tree.h"
using namespace std;

class Node {
    public:
        int value, height;
        Node *left, *right;
        Node(int value) : 
            value(value), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
    private:
        Node *root = nullptr;
        vector<int> nums;
        size_t size = 0;

        // Find the maximal node in left subtree
        Node *find_max_left_tree(Node *node) {
            while(node->left)
                node = node->left;
            return node;
        }

        // Return (int)height of node
        int get_height_node(Node *node) {
            return (node) ? node->height : 0;
        }

        // Return (int)balanced_factor of node
        int bf(Node *node) {
            return (node) ?
                    get_height_node(node->left) - get_height_node(node->right) :
                    0;
        }

        // Function update the height of node
        void update_height(Node *node) {
            if (node)
                node->height = 1 + max(
                    get_height_node(node->left),
                    get_height_node(node->right)
                );
        }

        // Functional rotation - Right
        Node *right_rotation(Node *node) {
            Node *left = node->left;
            Node *T2 = left->right;
            left->right = node; // Right rotation
            node->left = T2; // Assign T2 to avoid it
            update_height(node); // Update new height for node
            update_height(left); // Update new height for left
            return left;
        }

        // Functional rotation - Left
        Node *left_rotation(Node *node) {
            Node *right = node->right;
            Node *T2 = right->left;
            right->left = node; // Left rotation
            node->right = T2; // Assign T2 to avoid it
            update_height(node); // Update new height for node
            update_height(right); // Update new height for right
            return right;
        }

        // Rebalance tree
        Node *rebalance(Node *node) {
            update_height(node); // Update height of node before calculating balanced factor
            int balanced_factor = bf(node);

            // If the root is left heavy
            if (balanced_factor > 1) {
                // If the node --> left is right heavy
                if (bf(node->left) < 0)
                    node->left = left_rotation(node->left); // Left - Right
                return right_rotation(node); // Right - Right
            }

            // Else if the root is right heavy
            else if (balanced_factor < -1) {
                // If the node --> right is left heavy
                if (bf(node->right) > 0)
                    node->right = right_rotation(node->right); // Right - Left
                return left_rotation(node); // Left - Left
            }

            // Else
            return node;
        }
    public:
        AVLTree(const vector<int> &nums) : nums(nums) {
            for (int i = 0; i < (int)nums.size(); i++)
                root = insert(root, nums[i]);
        }

        // Return root of AVL Tree
        Node *get_root() { return root; }

        // Function push a new node to tree
        Node *insert(Node *root, int value) {
            if (!root) return new Node(value);

            if (root->value > value)
                root->left = insert(root->left, value);
            else if (root->value < value)
                root->right = insert(root->right, value);
            else return root;
            
            return rebalance(root); // Rebalance when traversaling a node
        }

        // Function delete a node in the tree
        // Return the node replaced
        Node *pop(Node *root, int value) {
            if (!root) return nullptr;

            if (root->value > value) 
                root->left = pop(root->left, value);
            else if (root->value < value)
                root->right = pop(root->right, value);
            else {
                if (!root->left || !root->right) {
                    auto temp = (!root->left) ? root->right : root->left;
                    delete root;
                    return temp;
                } else {
                    auto predecessor = find_max_left_tree(root->left);
                    root->value = predecessor->value;
                    root->left = pop(root->left, predecessor->value);
                }
            }

            return rebalance(root); // Rebalance when traversaling a node
        }
};

int main() {
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};

    AVLTree avl(nums);
    Node *root = avl.get_root();

    trees::printTree<Node>(root);

    return 0;
}