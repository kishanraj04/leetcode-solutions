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



void helper(TreeNode *root,vector<int> &res,int level,int &pl){
    if(!root) return;
    
    if(level>pl || pl==0){
        res.push_back(root->val);
    }
    // cout<<level<<" ";
    helper(root->right,res,level+1,pl);
   
    helper(root->left,res,level+1,pl);
     if(level>pl){
        pl = level;
     }
}


public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int pl = 0;
        helper(root,res,0,pl);
        return res;
    }
};