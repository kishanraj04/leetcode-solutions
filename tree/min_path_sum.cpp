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

bool helper(TreeNode * h , int sum,int targetSum){
    if(h==NULL) return false;

    sum+=h->val;
    if(!h->left && !h->right){
        // cout<<"sum "<<sum<<" val "<<h->val<<endl;
        return sum==targetSum;
    }
    bool l = helper(h->left,sum,targetSum);
    bool r = helper(h->right,sum,targetSum);
    
    return l||r;
}

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return helper(root,sum,targetSum);
    }
};