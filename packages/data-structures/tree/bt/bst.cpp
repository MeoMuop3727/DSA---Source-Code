#include <bits/stdc++.h>
#include "../tree.h"
using namespace std;

class BinarySearchTree {
    private:
        size_t size; 
        vector<int> nums;
        Node *root = nullptr;

        // Function return the minimal node in left tree
        // Return the node
        // + Time Complexity: O(n)
        // + Space Complexity: O(1)
        Node *find_max_left_tree(Node *root) {
            while (root->right)
                root = root->right;
            return root;
        }

    public:
        BinarySearchTree(const vector<int> &nums) : nums(nums) {
            for (const int &element : nums)
                root = push(element, root);
        }

        // Return the root of tree
        Node *get_root() { return root; }

        // Function add a new node to binary search tree
        // Return the new node
        // + Time Complexity: O(n)
        // + Space Complexity: O(1)
        Node *push(int value, Node *root) {
            Node *newNode = new Node(value);

            if (!root) return newNode;
            
            if (root->value > value)
                root->left = push(value, root->left);
            else root->right = push(value, root->right);

            return root;
        }

        // Function finds a node in binary search tree
        // Return bool
        // + Time Complexity: O(n)
        // + Space Complexity: O(n)
        bool count(int value, Node *root) {
            if (!root) return false;

            queue<Node*> q;
            q.push(root);

            while (!q.empty()) {
                Node *current = q.front(); q.pop();
                if (current->value == value) return true;
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }

            return false;
        }

        // Function finds and deletes a node in binary search tree
        // + Time Complexity: O(h)
        // + Space Complexity: O(1)
        Node *pop(int value, Node *root) {
            /*
                Pop a value in binary search tree is same as deleting one
                on others, but we will have ways to connect a node 
                with the next node of node deleted
                    + If the node deleted is leaf, just delete it
                    + If the node just has one, choose it to replace the node deleted
                    + If the node has two children, we have two ways:
                        - Choose maximal node in left tree (Predecessor)
                        - Choose minimal node in right tree (Successor)
                In here, we trust focus on choose maximal in node left
            */
            if (!root) return nullptr;

            if (root->value > value)
                root->left = pop(value, root->left);
            else if (root->value < value)
                root->right = pop(value, root->right);
            else {
                // If the node is leaf or has one
                if (!root->left) {
                    auto temp = root->right;
                    delete root;
                    size--;
                    return temp;
                } else if (!root->right) {
                    auto temp = root->left;
                    delete root;
                    size--;
                    return temp;
                }
                // If the has children
                else {
                    auto predecessor = find_max_left_tree(root->left);
                    root->value = predecessor->value;
                    root->left = pop(predecessor->value, root->left);
                }
            }

            return root;
        }
};

int main() {
    vector<int> nums = {8,3,10,1,6,4};

    BinarySearchTree bst(nums);
    Node *root = bst.get_root();

    printTree(root);

    return 0;
}