class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        if (root->left) {
            if (!root->left->left && !root->left->right)
                sum += root->left->val;
        }
        return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};