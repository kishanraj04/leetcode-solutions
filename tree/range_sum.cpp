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

void sum(TreeNode *lp , TreeNode *rp , int h , int l,int &s){
    if(!lp && !rp) return;
    
    if(lp && lp->val>=l && lp->val<=h){
        s+=lp->val;
    }
    if(rp && rp->val>=l && rp->val<=h){
        s+=rp->val;
    }
   
   if(lp && rp){
     sum(lp->left,rp->left,h,l,s);
     sum(lp->right,rp->right,h,l,s);
   }

}

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root->val<low && root->val>high){
            return 0;
        }
        int s = 0;
        sum(root->left,root->right,high,low,s);
        // cout<<s;
        return root->val>=low && root->val<=high ? s+root->val:s;
    }
};