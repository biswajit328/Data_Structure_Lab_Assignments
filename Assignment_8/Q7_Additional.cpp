#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void inorder(Node* root, vector<int>& v) {
    if (!root) return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

Node* mergeVectors(const vector<int>& v) {
    if (v.empty()) return NULL;
    Node* head = new Node(v[0]);
    Node* curr = head;

    for (int i = 1; i < v.size(); i++) {
        Node* temp = new Node(v[i]);
        curr->right = temp;
        temp->left = curr;
        curr = temp;
    }
    return head;
}

Node* mergeBSTsToDLL(Node* root1, Node* root2) {
    vector<int> a, b, c;
    inorder(root1, a);
    inorder(root2, b);

    c.resize(a.size() + b.size());
    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());

    return mergeVectors(c);
}