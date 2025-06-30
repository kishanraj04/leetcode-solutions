/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

int helper(TreeNode *root,int &m){
    if(!root) return 0;

    int lh = helper(root->left,m);
    int rh = helper(root->right,m);
    m = max(m,lh+rh);
    return 1+max(lh,rh);
}

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int m = 0;
        cout<<m;
        helper(root,m);
        return m;
    }
};