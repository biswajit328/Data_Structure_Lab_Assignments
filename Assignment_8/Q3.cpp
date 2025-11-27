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

class BST {
public:
    Node* root;
    BST() { root = nullptr; }

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int val) {
        if (!node) return node;
        if (val < node->data) node->left = deleteNode(node->left, val);
        else if (val > node->data) node->right = deleteNode(node->right, val);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    int maxDepth(Node* node) {
        if (!node) return 0;
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        return max(leftDepth, rightDepth) + 1;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main() {
    BST tree;
    int choice, val;
    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Display Inorder\n4. Maximum Depth\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                tree.root = tree.insert(tree.root, val);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                tree.root = tree.deleteNode(tree.root, val);
                break;
            case 3:
                cout << "Inorder: ";
                tree.inorder(tree.root);
                cout << endl;
                break;
            case 4:
                cout << "Maximum Depth: " << tree.maxDepth(tree.root) << endl;
                break;
            case 5:
                return 0;
        }
    }
}