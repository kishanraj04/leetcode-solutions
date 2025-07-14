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
int helper(TreeNode*root,int cmin , int cmax){
    if(!root) return abs(cmax-cmin);
    
    cmin = min(cmin,root->val);
    cmax = max(cmax,root->val);

    int l = helper(root->left,cmin,cmax);
    int r = helper(root->right,cmin,cmax);
    return max(l,r);
}
public:
    int maxAncestorDiff(TreeNode* root) {
        return helper(root,root->val,root->val);
        
    }
};