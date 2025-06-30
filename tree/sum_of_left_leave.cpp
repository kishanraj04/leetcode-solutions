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

void helper(TreeNode *root , vector<TreeNode*> &dup , int &sum){
     
     if(!root) return;

     if(find(dup.begin(),dup.end(),root)==dup.end() && !root->left && !root->right){
        sum+=root->val;
     }

     dup.push_back(root->right);
     helper(root->left,dup,sum);
     helper(root->right,dup,sum);


}

public:
    int sumOfLeftLeaves(TreeNode* root) {
         vector<TreeNode*> dup;
         int sum=0;
         dup.push_back(root);
         helper(root,dup,sum);
         return sum;    
    }
};