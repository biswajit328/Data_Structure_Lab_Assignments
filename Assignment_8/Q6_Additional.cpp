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

Node* buildTree(vector<int>& inorder, vector<int>& postorder, int& postIndex, int start, int end) {
    if (start > end)
        return nullptr;

    int curr = postorder[postIndex--];
    Node* root = new Node(curr);

    if (start == end)
        return root;

    int pos = searchInorder(inorder, start, end, curr);

    root->right = buildTree(inorder, postorder, postIndex, pos + 1, end);
    root->left = buildTree(inorder, postorder, postIndex, start, pos - 1);

    return root;
}

void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    int postIndex = postorder.size() - 1;
    Node* root = buildTree(inorder, postorder, postIndex, 0, inorder.size() - 1);

    cout << "Inorder Traversal of Constructed Tree: ";
    inorderPrint(root);
    return 0;
}
