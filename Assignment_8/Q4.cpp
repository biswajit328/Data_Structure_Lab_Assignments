#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

bool isBSTUtil(Node* node, int min, int max) {
    if (!node) return true;
    if (node->data <= min || node->data >= max) return false;
    return isBSTUtil(node->left, min, node->data) && isBSTUtil(node->right, node->data, max);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    if (isBST(root)) cout << "Tree is a BST\n";
    else cout << "Tree is not a BST\n";
}