#include <bits/stdc++.h> 
using namespace std;

class Node {
    public:
        char c;
        bool isEnd = false;
        vector<Node*> children;
        Node(char c) : c(c), children(26, nullptr) {}
};

class TrieTree {
    private:
        vector<string> strs;
        Node *root = new Node(' ');

        // Return (bool)empty of node's children
        bool isEmpty(Node *node) {
            for (int i = 0; i < 26; i++)
                if (node->children[i]) return false;
            return true;
        }

        // Function helper of pop function
        Node *helper(Node *node, const string &str, int depth = 0) {
            if (!node) return nullptr;

            if (depth == (int)str.size()) {
                // If the node is end
                // Assign it false to make it is not the end
                if (node->isEnd) node->isEnd = false;
                // If node is empty
                // This means it is end and empty --> useless node
                if (isEmpty(node)) {
                    delete node;
                    return nullptr;
                }
                // Else, node is not empty
                return node;
            }

            int index = str[depth] - 'a'; // The index to traversal
            // Assign node to avoid it
            node->children[index] = helper(node->children[index], str, depth + 1);

            // Address medium nodes
            // If the node is empty and it is not the end
            // For example, delete banana
            // Delete a -> n (because after deleting a, n's children is empty), delete n
            // It is the same with remain nodes
            if (isEmpty(node) && !node->isEnd) {
                delete node;
                return nullptr;
            }

            return node;
        }

    public:
        TrieTree(const vector<string> &strs) : strs(strs) {
            for (const string str : strs) insert(str);
        }

        // Function inserts a new node to tree
        void insert(const string &str) {
            Node *node = root; // To traversal 

            // Traversal each char of (string) str
            for (const char c : str) {
                int index = c - 'a'; // The index of character alphabet
                // If the chil of node is not exist
                // Create it and go to the next character
                if (!node->children[index]) 
                    node->children[index] = new Node(c);

                // Else
                // Just go to the next character
                node = node->children[index];
            }

            // The last character will tick it is last
            node->isEnd = true;
        }

        // Function finds a node in the tree
        // Return bool
        bool find(const string str) {
            Node *node = root; // To traversal
            
            // Traversal each char of (string)str
            for (const char &c : str) {
                int index = c - 'a'; // The index of character alphabet
                // If the child at index is not existed
                // Return false
                if (!node->children[index]) return false;
                // Else
                node = node->children[index];
            }

            // If we can traversal the end of node
            // This means the string is in the tree
            // Return true
            // Else, return false
            return node->isEnd;
        }

        // Function delete a node in tree
        void pop(const string &str) { root = helper(root, str); }
};

int main() {
    vector<string> strs = {"cat", "cats", "banana"};
    TrieTree tt(strs);
    return 0;
}