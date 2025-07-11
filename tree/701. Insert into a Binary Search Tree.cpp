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

TreeNode *helper(TreeNode *root,int v){
    if(!root) return nullptr;

    if(root->val<v){
        if(!root->right){
            root->right = new TreeNode(v);
            return root;
        }
        helper(root->right,v);
        
    }else{
        if(!root->left){
            root->left = new TreeNode(v);
            return root;
        }
        helper(root->left,v);
    }

    return root;
}

public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        return helper(root,val);
    }
};