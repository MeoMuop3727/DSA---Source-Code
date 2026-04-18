#include <bits/stdc++.h>
#include "../tree.h"
using namespace std;

#define RED 1
#define BLACK 0

class Node {
    public:
        int value;
        int color; // Red - 1, Black - 0
        Node *parent, *left, *right;
        Node(int value)
            : value(value), parent(nullptr), left(nullptr), right(nullptr) {}
};

class RedBlackTree {
    private:
        vector<int> nums;
        Node *root = nullptr;

        // Return (Node)maximum of the left side subtree
        Node *find_max_left_tree(Node *node) {
            while (node->right) 
                node = node->right;
            return node;
        }

        // Return (Node)parent of node
        Node *get_parent(Node *node) { return (node) ? node->parent : nullptr; }

        // Return (Node)sibling of node
        Node *get_sibling(Node *node) {
            if (node) {
                Node *parent = get_parent(node);
                if (!parent) return nullptr;
                return (node == parent->left) ? parent->right : parent->left;
            }
            return nullptr;
        }

        // Return (Node)uncle of node
        Node *get_uncle(Node *node) {
            if (node) {
                Node *parent = node->parent;
                Node *grandparent = get_parent(parent);

                if (!grandparent) return nullptr;

                if (grandparent->left == parent) return grandparent->right;
                else return grandparent->left;
            }
            return nullptr;
        }

        // Return (int)color of node
        int get_color(Node *node) { return (node) ? node->color : BLACK; }

        // Left rotation
        void left_rotation(Node *&root, Node *node) {
            if (!node || !node->right) return;

            Node *right = node->right;
            Node *parent_node = get_parent(node); // Get parent of node
            node->right = right->left; // Get T2 and assign it to the right side node

            // If the T2 is existed
            // Update new parent, from right to node
            if (right->left)
                right->left->parent = node;

            // The node has not parent
            // This means node is root
            // Update root
            if (!parent_node) root = right;
            
            // Else
            else {
                // If the node is the side left
                // Update new connection between right and parent's node
                if (node == parent_node->left)
                    parent_node->left = right;
                // Else
                else parent_node->right = right;
            }

            right->parent = node->parent; // Update new parent for right
            node->parent = right; // Update new parent for node
            right->left = node; // Rotate left
        }

        // Right rotation
        void right_rotation(Node *&root, Node *node) {
            if (!node || !node->left) return;

            Node *left = node->left;
            Node *parent_node = get_parent(node); // Get parent of node
            node->left = left->right; // Get T2 and assign it to the left side node

            // If the T2 is existed
            // Update new parent, from left to node
            if (left->right)
                left->right->parent = node;

            // The node has not parent
            // This means node is root
            // Update root
            if (!parent_node) root = left;

            // Else
            else {
                // If the node is the side left
                // Update new connection between left and parent's node
                if (node == parent_node->left)
                    parent_node->left = left;
                // Else
                else parent_node->right = left;
            }

                left->parent = node->parent; // Update new parent for left
                node->parent = left; // Update new parent for node
                left->right = node; // Rotate right
        }

        // Function rebalances tree for insertion
        void helperInsert(Node *node) {
            // We will rebalance from node which inserted or deleted
            // From bottom to up
            // If the node != root and their parent's color is red
            while (node != root && get_color(get_parent(node)) == RED) {
                Node *uncle = get_uncle(node);
                Node *parent = get_parent(node);
                Node *grandparent = get_parent(parent);

                // If the node is do not have grandparent
                // Break the loop
                if (!grandparent) break;

                // We will divide two case according to uncle node
                // Firstly, the uncle's color is red
                // We just need recolor
                if (get_color(uncle) == RED) {
                    // Recolor nodes
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    grandparent->color = RED;
                    node = grandparent; // Translate node into grandparent to go up
                } 
                
                // Else, the unclde's is black
                // We will rotate
                else {
                    // If the parent is left side 
                    if (grandparent->left == parent) {
                        // And if the node is right side
                        if (parent->right == node) {
                            left_rotation(root, parent); // Left - Right
                            // Update new node after rotating
                            node = parent; // node --> parent
                            parent = get_parent(node); // parent --> node
                        }
                        right_rotation(root, grandparent); // Right - Right 
                    }
                    // If the parent is right side
                    else {
                        // And if the node is left side
                        if (parent->left == node) {
                            right_rotation(root, parent); // Right - Left
                            // Update new node after rotating 
                            node = parent; // node --> parent
                            parent = get_parent(node); // parent --> node
                        }
                        left_rotation(root, grandparent); // Left - Left
                    }

                    parent->color = BLACK; // Recolor parent
                    grandparent->color = RED; // Recolor grandparent
                }
            }

            root->color = BLACK;    // Always maintain root's color is black
                                    // After rebalancing
        }

        // Function rebalances tree for deletion
        void helperDelete(Node *node) {
            while (node != root && get_color(node) == BLACK) {
                Node *parent = get_parent(node);
                Node *sibling = get_sibling(node);

                //
                if (get_color(sibling) == RED) {
                    sibling->color = BLACK;
                    parent->color = RED;

                    if (node == parent->left) left_rotation(root, parent);
                    else right_rotation(root, parent);
                } else {
                    if (get_color(sibling->left) == BLACK &&
                        get_color(sibling->right) == BLACK) {
                            sibling->color = RED;
                            node = parent;
                        }
                    else {
                        if (node == parent->left &&
                            get_color(sibling->right) == BLACK) {
                                sibling->left->color = BLACK;
                                sibling->color = RED;
                                right_rotation(root, sibling);
                                sibling = parent->right;
                            }
                        else if (node == parent->right &&
                                get_color(sibling->left) == BLACK) {
                                    sibling->right->color = BLACK;
                                    sibling->color = RED;
                                    left_rotation(root, sibling);
                                    sibling = parent->left;
                                }
                        sibling->color = parent->color;
                        parent->color = BLACK;

                        if (node == parent->left) {
                            sibling->right->color = BLACK;
                            left_rotation(root, parent);
                        } else {
                            sibling->left->color = BLACK;
                            right_rotation(root, parent);
                        }

                        node = root;
                    }
                }
            }

            node->color = BLACK;
        }
    public:
        RedBlackTree(const vector<int> &nums) {
            for (const int &element : nums) 
                root = insert(element);
            }

        // Return (Node)root of tree
        Node *get_root() { return root; }

        // Function inserts a new node to Red Black Tree
        Node *insert(int value) {
            Node *newNode = new Node(value);
            newNode->color = RED; // Assign the newNode's color is red

            Node *parent = nullptr; // Save parent node
            Node *current = root; // A var which use for traversaling

            while (current) {
                parent = current;
                if (value < current->value) 
                    current = current->left;
                else if (value > current->value)
                    current = current->right;
                else return root;
            }

            newNode->parent = parent; // Update parent for newNode

            // If parent is not existed
            // This means the tree has one node, it is newNode
            // Therefore, newNode will become root
            if (!parent) root = newNode; 
            
            // Else
            // Check the position of value to make connection between parent and newNode
            else if (value < parent->value) parent->left = newNode;
            else parent->right = newNode;

            helperInsert(newNode); // Rebalance from newNode to root
                                // This means the newNode must be determinated

            return root; // Return the root changed
        }

        // Function deletes a new node in Red Black Tree
        // Node *pop(int value, Node *root) {
        //     Node *node = trees::searchTree(root, value);
        //     Node *parent = get_parent(node);

        //     if (!node || !parent) return nullptr;

        //     if (!node->left || !node->right) {
        //         auto temp = (!node->left) ? node->right : node->left;
        //         if (node == parent->left) parent->left = temp;
        //         else parent->right = temp;
        //         temp->parent = parent;
        //         delete node;
        //         helperDelete(temp);
        //         return temp;
        //     } else {
        //         auto predecessor = find_max_left_tree(node->left);
        //         node->value = predecessor->value;
        //         node->left = pop(predecessor->value, node->left);
        //     }

        //     return root;
        // }
};

int main() {
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    RedBlackTree rbt(nums);

    Node *root = rbt.get_root();

    // rbt.pop(5, root);

    trees::printTree<Node>(root);

    return 0;
}
