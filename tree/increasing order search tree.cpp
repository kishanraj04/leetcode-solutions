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

void create(TreeNode *root,TreeNode * &res){
    if(!root) return;

    create(root->left,res);
    res->right = new TreeNode(root->val);
    res=res->right;
    create(root->right,res);
    
}

public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *res = new TreeNode(0);
        TreeNode *tmp = res;
        create(root,res);
        return tmp->right;
    }
};