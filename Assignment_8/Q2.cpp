#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int key) {
    if (!root)
        return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (!root || root->data == key)
        return root;
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

Node* searchNonRecursive(Node* root, int key) {
    while (root) {
        if (root->data == key)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}

Node* findMax(Node* root) {
    if (!root)
        return nullptr;
    while (root->right)
        root = root->right;
    return root;
}

Node* findMin(Node* root) {
    if (!root)
        return nullptr;
    while (root->left)
        root = root->left;
    return root;
}

Node* inorderSuccessor(Node* root, Node* target) {
    if (!root || !target) return nullptr;
    if (target->right)
        return findMin(target->right);
    Node* successor = nullptr;
    Node* ancestor = root;
    while (ancestor != target) {
        if (target->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return successor;
}

Node* inorderPredecessor(Node* root, Node* target) {
    if (!root || !target) return nullptr;
    if (target->left)
        return findMax(target->left);
    Node* predecessor = nullptr;
    Node* ancestor = root;
    while (ancestor != target) {
        if (target->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return predecessor;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : arr)
        root = insert(root, x);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\n";

    int key = 40;
    cout << "\nSearching for " << key << " (Recursive): ";
    cout << (searchRecursive(root, key) ? "Found" : "Not Found");

    cout << "\nSearching for " << key << " (Non-Recursive): ";
    cout << (searchNonRecursive(root, key) ? "Found" : "Not Found");

    cout << "\n\nMaximum element: " << findMax(root)->data;
    cout << "\nMinimum element: " << findMin(root)->data;

    Node* target = searchRecursive(root, 60);
    Node* succ = inorderSuccessor(root, target);
    cout << "\n\nInorder Successor of 60: ";
    if (succ) cout << succ->data; else cout << "None";

    Node* pred = inorderPredecessor(root, target);
    cout << "\nInorder Predecessor of 60: ";
    if (pred) cout << pred->data; else cout << "None";

    return 0;
}