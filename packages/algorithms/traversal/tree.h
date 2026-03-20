#include <vector>
using namespace std;


class Node {
    public:
        int value;
        Node* left;
        Node* right;
        Node(int value) : value(value), left(nullptr), right(nullptr) {}
};


class BinaryTree {
    public:
        BinaryTree(vector<int> nums) : nums(nums) {
            root = buildBinaryTree(0); // Build Binary Tree
        }


        Node* get_root() { return root; }


    private:
        vector<int> nums;
        Node* root;


        Node* buildBinaryTree(int index) {
            if (index >= nums.size()) return nullptr;
            Node* newNode = new Node(nums[index]);
            newNode -> left = buildBinaryTree(2 * index + 1);
            newNode -> right = buildBinaryTree(2 * index + 2);
            return newNode;
        }
};

void preorder(Node* root) {


    // Pre-order traversal is defined: "Root -> Left -> Right"


    if (root == nullptr) return;


    cout << root -> value << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(Node* root) {


    // In-order traversal is defined: "Left -> Root -> Right"


    if (root == nullptr) return;


    inorder(root -> left);
    cout << root -> value << " ";
    inorder(root -> right);
}

void postorder(Node* root) {


    // Post-order traversal is defined: "Left -> Right -> Root"


    if (root == nullptr) return;


    postorder(root -> left);
    postorder(root -> right);
    cout << root -> value << " ";
}
