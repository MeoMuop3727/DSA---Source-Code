#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int value;
        vector<Node*> children;
        Node(int __value) : value(__value) {}
};

class NAry {
    private:    
        Node *root = new Node(-1);
        int height = 0; // Height of tree

        // Clean subtree of root
        void clean_root(Node *node) {
            if (!node) return;
            for (auto &child : node->children)
                clean_root(child);
            delete node;
        }

        // Return (int)height of tree
        // Use for calculate the height
        int helperHeight(Node *root) {
            if (!root) return 0;
            int h = 0;
            for (auto &child : root->children)
                h = max(h, helperHeight(child));
            return h + 1;
        }
    
    public:
        NAry(const vector<int> nums) {
            for (const auto &element : nums)
                insert(root, element);
            height = helperHeight(root);
        }

        // Return (Node)root of tree
        Node *get_root() { return root; }

        // Return (int)height of tree
        int get_height() { return height; }

        // Function print tree
        void print(Node *node) {
            if (!node) return;
            
            if (node->value == root->value) cout << "root" << " ";
            else cout << node->value << " ";

            for (auto &child : node->children) 
                print(child);
        }

        /**
         * @brief Insert a new node to the tree
         * @param parent The root wanna insert
         * @param value The value wanna insert
         */
        void insert(Node *parent, int value) {
            if (!parent) return;
            parent->children.push_back(new Node(value));
            height = helperHeight(root); // Reset the height of tree
        }

        /**
         * @brief Find nodes from the root to end
         * @param root The pos wanna start
         * @param target The target wanna find
         * @return A vector<Node*> save nodes found
         */
        vector<Node*> find(Node *root, int target) {
            if (!root) return {};

            queue<Node*> q; q.push(root);
            vector<Node*> children;

            while (!q.empty()) {
                auto current = q.front(); q.pop();
                if (current->value == target) 
                    children.push_back(current);

                for (auto &child : current->children)
                    q.push(child);
            }

            return children;
        }

        /**
         * @brief Delete a node and their subtree in the tree
         * @param root The pos wanna start
         * @param target The target wanna delete
         */
        void pop(Node *root, int target) {
            if (!root) return;

            for (auto it = root->children.begin(); it != root->children.end(); it++)
                if ((*it)->value == target) {
                    Node *targetNode = *it; // To avoid being too dependent on it
                    clean_root(targetNode); // Clean subtree in root
                    root->children.erase(it); // Delete the connection
                    height = helperHeight(get_root()); // Reset the height of tree
                    return;
                }
            
            // Else, cannot find any target, go deeper
            for (auto &child : root->children) pop(child, target);
        }
};

int main() {
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    NAry nary(nums);

    Node *root = nary.get_root();

    return 0;
}
