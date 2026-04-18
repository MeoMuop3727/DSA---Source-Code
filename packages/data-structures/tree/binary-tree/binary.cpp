#include <bits/stdc++.h>
#include "../tree.h"
using namespace std;

class BinaryTree {
    private: 
        size_t size = 0;
        vector<int> nums;
        Node *root = nullptr;

        // Function build binary tree from array
        // Time complexity: O(n)
        // Space complexity: O(1)
        Node *build(const vector<int> &nums, int index) {
            if (index >= (int)nums.size()) return nullptr;

            Node *newNode = new Node(nums[index]);
            newNode->left = build(nums, 2 * index + 1);
            newNode->right = build(nums, 2 * index + 2);

            size++;

            return newNode;
        }
    public:
        BinaryTree(const vector<int> &nums) { root = build(nums, 0); }

        // Return the number of nodes
        size_t get_size() { return size; }

        // Return root
        Node *get_root() { return root; }

        // Function print tree
        // It uses DFS (inorder)
        // You can try other traversals in chapter 3 of part 2
        // Link: https://docs.google.com/document/d/1dLv27jtNVUy4ENpErXD2go5Ks8AUoPCk3iGlQPM6hbY/edit?tab=t.qh3y8tp9js44#heading=h.hxvsm2lw4drg
        void print(Node *root) {
            if (!root) return;
            print(root->left);
            cout << root->value << " ";
            print(root->right);
        }

        // Function add new node by using BFS
        // Time complexity: O(n)
        // Space complexity: O(n)
        void push(int value, Node *root) {
            Node *newNode = new Node(value);

            // If root is not existed
            // Create a new root
            if (!root) root = newNode;

            queue<Node*> q;
            q.push(root);

            while (!q.empty()) {
                Node *current = q.front(); q.pop();

                if (!current->left) {
                    current->left = newNode;
                    size++;
                    return;
                } else if (!current->right) {
                    current->right = newNode;
                    size++;
                    return;
                }

                q.push(current->left);
                q.push(current->right);
            }
        }

        // Function find node by using BFS
        // Time complexity: O(n)
        // Space complexity: O(n)
        void count(int value, Node *root) {
            // If root is not existed
            // Print 0, it is mean not found
            if (!root) {
                cout << 0 << "\n";
                return;
            }

            queue<Node*> q;
            q.push(root);

            while (!q.empty()) {
                Node *current = q.front(); q.pop();

                if (current->value == value) {
                    cout << 1 << "\n";
                    return;
                }

                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
        }
};

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};

    BinaryTree binary_tree(nums);
    Node *root = binary_tree.get_root();

    binary_tree.push(10, root);
    binary_tree.print(root);
    cout << "\n";
    cout << binary_tree.get_size() << "\n";
    binary_tree.count(6, root);

    return 0;
}