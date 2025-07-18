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

// int mv = 0;
int good = 0;
void helper(TreeNode *root,int m){
    if(!root) return ;
    
    if(root->val>=m){
        good++;
        m = root->val;
    }

    helper(root->left,m);
    helper(root->right,m);

    // return good;
}

public:
    int goodNodes(TreeNode* root) {
         helper(root,INT_MIN);
         return good;
    }
};