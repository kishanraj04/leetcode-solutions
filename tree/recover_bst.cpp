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

    void inorder(TreeNode* root, long& prev, TreeNode*& first, TreeNode*& mid,
                 TreeNode*& last) {
        if (!root)
            return;

        inorder(root->left, prev, first, mid, last);
        // cout<<root->val;
        if (root->val >= prev) {
            prev = root->val;
            if (!mid)
                first = root;
        } else {
            if (!mid) {
                mid = root;
            } else {
                last = root;
            }
            prev = root->val;
        }
        inorder(root->right, prev, first, mid, last);
    }

public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* mid = nullptr;
        TreeNode* last = nullptr;

        long prev = LONG_MIN;
        inorder(root, prev, first, mid, last);
        cout << last;
        if (last) {
            int v = first->val;
            first->val = last->val;
            last->val = v;
        } else {
            int v = first->val;
            first->val = mid->val;
            mid->val = v;
        }
    }
};