#include <bits/stdc++.h>
using namespace std;


class Node {
    public:
        int freq; // Existing frequence of each character
        Node *left, *right; // Node left and Node right
        Node (int freq) : freq(freq), left(nullptr), right(nullptr) {}
};


// Using min-heap to sort character according to freq
class Compare {
    public:
        bool operator() (Node *a, Node *b) {
            return a->freq > b->freq;
        }
};


// Using pre-order (DFS in tree) to traversal all vertices
// of huffman tree
void preOder(Node *root, vector<string> &ans, string cur) {
    if (root == nullptr) return; // If can not be continue, back tracking


    // If root is leaf, it means we arrived end path
    // Push coding to ans
    // And back tracking
    if (root->left == nullptr && root->right == nullptr) {
        ans.push_back(cur);
        return;
    }


    preOder(root -> left, ans, cur + "0"); // Traversal to left, updated coding by current coding + "0"
    preOder(root -> right, ans, cur + "1"); // Traversal to right, updated coding by current scoding + "1"
}


vector<string> Huffman(vector<int> freq) {
    priority_queue <
        Node*,
        vector<Node*>,
        Compare
    > pq; // pq sorts Nodes according to freq
    vector<string> ans; // Store Huffman codings of each character


    // Creating Node for each character
    // And push it to pq
    for (int &e : freq) {
        Node *newNode = new Node(e);
        pq.push(newNode);
    }


    // Traversal all elements in pq
    // Choosing two smallest elements and meger them into a node
    // With newNode by total of freq element 1 and element 2
    // Connecting Node left and Node right with newNode
    // Push newNode to pq
    // Repeat process until only having one
    while (pq.size() >= 2) {
        // Node left
        Node *left = pq.top(); pq.pop();


        // Node right
        Node *right = pq.top(); pq.pop();


        // Create newNode
        Node *newNode = new Node(left->freq + right->freq);
        // Connect node left and node right
        // To newNode
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }


    // Current, only one in pq, this is root
    // With freq by total of all freqs of each character
    Node *root = pq.top(); pq.pop();
    // Traversal nodes in huffman tree
    // And create coding for each character
    // And update it to ans
    preOder(root, ans, "");
   
    return ans;
}


void Decoding(string str, vector<string> ans, string coding) {
    map<string, char> mp; // Store codings (key) for each character (char)
    int i = 0;
    for (string &e : ans) { mp[e] = str[i]; i++; } // Update mp


    // Decompressing algorithm pre-fix coding
    // Time complexity: O(n)
    // Traversal each character in the coding, update key
    // If key duplicate with key in mp
    // Decompress it and update key = ""
    // Repeat the process until finish
    string key = "";
    for (auto &e : coding) {
        key += e;
        // If key duplicate with key in mp
        if (mp.count(key)) {
            cout << mp[key]; // Print character is respective key in mp
            key = ""; // Update key = ""
        }
    }
    cout << "\n";
}




int main() {
    string str = "abcdfe"; // String need to compress
    string coding = ""; // Save coding compressed
    vector<int> freq = {1,2,3,4,5,6}; // The number of existing time of character in str
    vector<string> ans = Huffman(freq); // Store coding is respective each character in str


    int index = 0;
   
    // Before compressing
    cout << "Before compressing: \t";
    for (int &e : freq) {
        for (int i = 0; i < e; i++) {
            cout << str[index];
        }
        index++;
    }


    index = 0; cout << "\n";


    // After compressing
    cout << "After compressing: \t";
    for (int &e : freq) {
        for (int i = 0; i < e; i++) {
            cout << ans[index];
            coding += ans[index];
        }
        index++;
    }


    cout << "\n";


    // Decompressing coding
    cout << "Decompressing coding: \t";
    Decoding(str, ans, coding);
}
