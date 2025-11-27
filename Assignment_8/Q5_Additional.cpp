#include <iostream>
#include <vector>
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

int searchInorder(vector<int>& inorder, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder, int& preIndex, int start, int end) {
    if (start > end)
        return nullptr;

    int curr = preorder[preIndex++];
    Node* root = new Node(curr);

    if (start == end)
        return root;

    int pos = searchInorder(inorder, start, end, curr);
    root->left = buildTree(preorder, inorder, preIndex, start, pos - 1);
    root->right = buildTree(preorder, inorder, preIndex, pos + 1, end);

    return root;
}

void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    int preIndex = 0;
    Node* root = buildTree(preorder, inorder, preIndex, 0, inorder.size() - 1);

    cout << "Inorder Traversal of Constructed Tree: ";
    inorderPrint(root);
    return 0;
}