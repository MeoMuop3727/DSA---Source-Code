#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int t;
        bool isLeaf;
        vector<int> keys;
        vector<Node*> children;

        Node(int __t, bool __isLeaf) : t(__t), isLeaf(__isLeaf) {
            keys.reserve(2*t - 1);
            children.reserve(2*t);
        }

        // Return bool if keys is full
        bool isFull() { return keys.size() == 2*t - 1; }
};

class BTree {
    private:
        const int t = 3; // The level of each node in the tree
        Node *root = nullptr;

        /**
         * @brief Split a children at i of the node parent
         * @param parent The node parent
         * @param i The index i of the children in parent's children
         */
        void split(Node *parent, int i) {
            Node *y = parent->children[i]; // Node is slipted, is left side
            int t = y->t; // The level t of y

            Node *right = new Node(t, y->isLeaf);    // Create new node saves a-half right of y
                                                    // The new node has same t with y
                                                    // The new node has same isLeaf with y, because if y is leaf, 
                                                    // leaf also is leaf
            int MEDIAN = y->keys[t - 1];  // Get the mid key in keys

            right->keys.assign(y->keys.begin() + t, y->keys.end()); // Copy a-half elements in keys of y
            y->keys.resize(t - 1); // Resize the keys to avoid accessing elements in right (elements copied)

            // If y have children
            // This mean key is not leaf
            // Must address y's children
            if (!y->isLeaf) {
                right->children.assign(y->children.begin() + t, y->children.end()); // Copy a-half elements in children of y
                y->children.resize(t); // Resize the children to avoid accessing elements in right (elements copied)
            }

            // Make MEDIAN became parent of right and y
            parent->keys.insert(parent->keys.begin() + i, MEDIAN); // Add MEDIAN to keys in parent at the index i
            parent->children.insert(parent->children.begin() + i + 1, right); // Add right to children in parent at the index i + 1
        }

        /**
         * @brief Insert a new node if the current is not full
         * @param node The current node
         * @param k The new key want to insert
         */
        void insertNoneFull(Node *node, int k) {
            int i = node->keys.size() - 1;

            // If node is leaf
            // We just need to insert the new keys to node's keys
            if (node->isLeaf) {
                node->keys.insert(
                    upper_bound(node->keys.begin(), node->keys.end(), k), // Find the pos need to insert to avoid sorting again
                    k // The element need to insert
                );
            } 
            // If node is not leaf
            // We must go deeper to until node is leaf
            // We will use "split function" to balance tree when traversaling to the leaf
            else {
                // Find the suitable range to insert
                // For example, 
                // keys = [10, 30], i = 1, k = 20
                // keys[1] = 30 > 20 && i >= 0 ==> i = 0;
                // keys[0] = 10 < 0 && i >= 0 ==> stop;
                /*
                    i = 0: (-inf, 10]
                    i = 1: [10, 30]
                    i = 2: [30, +inf)
                */
                // ==> 20 in (10; 30) <=> i = i + 1 = 1
                // Choose the children[1] and go to it
                while (i >= 0 && k < node->keys[i]) i--;
                i++;

                // If the node at i is full
                // We must split it to balance
                if (node->children[i]->isFull()) {
                    split(node, i);
                    // Choose another route to go
                    if (k > node->keys[i]) i++;
                }

                insertNoneFull(node->children[i], k); // Go deeper to the leaf
            }
        }

        // Function helper insert
        void helperInsert(Node *&root, int k) {
            // If root does not exist
            if (!root) {
                root = new Node(t, true); // Create new root
                root->keys.push_back(k); // Push the new key k to keys
                return;
            }

            // We will insert from root
            // If the root is full ==> split it
            if (root->isFull()) {
                Node *s = new Node(root->t, false); // Create new root to store old root
                                                    // The new root never is leaf because it has children

                s->children.push_back(root);    // Make old root into child root of root s
                                                // s --> root

                split(s, 0); // split old root

                root = s; // Update new root
            }

            insertNoneFull(root, k); // Go deeper to the leaf
        }

        // Function hepler find
        Node *helperFind(Node *root, int k) {
            if (!root) return nullptr; // If the root does not exist

            int i = 0; // The index i

            // Find the suitable range
            while (i < root->keys.size() && k > root->keys[i]) i++;

            // Check key, if the key at i == target, return the root which saved it
            if (i < root->keys.size() && k == root->keys[i]) return root;

            // If the current root did not save target
            // And the root is leaf, this means they do not have children
            if (root->isLeaf) return nullptr;

            // Else, the current root did not save target
            // And the root is not leaf
            return helperFind(root->children[i], k);
        }

        /**
         * 
         */

        // Function helper remove
        void helperRemove(Node *root, int k) {}

    public:
        BTree(const vector<int> nums) {
            for (const int &element : nums) insert(element);
        }

        // Return (Node)root of the tree
        Node *get_root() { return root; }

        // Function insert new key to the tree
        void insert(int k) { helperInsert(root, k); }

        // Function delete a key in the tree
        // void remove(int k) { helperRemove(root, k); }

        /**
         * @brief Return a node which has the key
         * @return Node*
         */
        Node *find(int k) { return helperFind(root, k); }
};

int main() {
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    BTree bt(nums);

    return 0;
}
