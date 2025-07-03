/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

    bool iC(TreeNode* root,long minv, long maxv) {
        if (!root)
            return true;

        if (root->val >= maxv || root -> val <= minv)
            return false;

        return iC(root->left,minv,root->val) && iC(root->right,root->val,maxv);
    }

public:
    bool isValidBST(TreeNode* root) {
        long minv = LONG_MIN;
        long maxv = LONG_MAX;
        return iC(root,minv,maxv);
    }
};