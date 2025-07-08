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

int ps = 0;
int helper(TreeNode* &root){
     if(!root) return 0;

    int rs = helper(root->right);
    ps = ps+root->val;
    root->val = ps;
    int ls = helper(root->left);

    return 0;
}

public:
    TreeNode* convertBST(TreeNode* root) {
          helper(root);
          return root;   
    }
};