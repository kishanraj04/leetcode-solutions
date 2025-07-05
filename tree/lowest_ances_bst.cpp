/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {

int minv = 0;
int maxv = 0;

void helper(TreeNode* root, TreeNode*& ans) {
    if (!root) return;

    // If both children match minv and maxv
    if (root->left && root->right &&
        root->left->val == minv && root->right->val == maxv) {
        ans = root;
        return;
    }

    // If root value lies between minv and maxv (inclusive)
    if (root->val >= minv && root->val <= maxv) {
        ans = root;
    }

    // Traverse the left or right subtree depending on value range
    if (maxv < root->val) {
        helper(root->left, ans);
    } else if (minv > root->val) {
        helper(root->right, ans);
    }

    // Debug output (optional)
    cout << root->val << " ";
}


public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         
        TreeNode *ans = NULL;
        minv = p->val<q->val?p->val:q->val;
        maxv = p->val>q->val?p->val:q->val;
        // if((minv<=root->val && maxv>=root->val)){
        //     return root;
        // }
        helper(root,ans);
        return ans;
    }
};