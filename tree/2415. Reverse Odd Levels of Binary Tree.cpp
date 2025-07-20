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

void rev(TreeNode *lp , TreeNode*rp,int level){
      if(!lp || !rp) return;
      
      if(level%2!=0){
        swap(lp->val,rp->val);
      }
      level++;
      rev(lp->left,rp->right,level);
      rev(lp->right,rp->left,level);
}

public:
    TreeNode* reverseOddLevels(TreeNode* root) {
       if(!root) return nullptr;
       rev(root->left,root->right,1);
       return root;
    }
};