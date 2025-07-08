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

string helper(TreeNode *root){
    if(!root) return "";

    string res = to_string(root->val);

    string left = helper(root->left);
    string right = helper(root->right);

    if(!root->left && !root->right){
        return res;
    }
   
   if(!root->left){
        return res+"()"+"("+right+")";
    }


    if(!root->right){
        return res+"("+left+")";
    }

    
    return res+"("+left+")"+"("+right+")";


}

public:
    string tree2str(TreeNode* root) {
        return helper(root);
    }
};