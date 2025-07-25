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
int sum = 0;
int helper(TreeNode* &root){
    if(!root) return 0;

    
   helper(root->right);
   sum = sum+root->val;
  root->val = sum;
   helper(root->left);
  
  return sum;
}

public:
    TreeNode* bstToGst(TreeNode* root) {
        helper(root);
        return root;
    }
};