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

int ml = 0;
int sum = 0;
void helper(TreeNode * root,int level){
    if(!root) return;
    
    if(!root->left && !root->right){
        if(level>ml){
            ml=level;
            sum = root->val;
        }
        else if(level==ml){
            sum+=root->val;
        }
    }
  

    helper(root->left,level+1);
    helper(root->right,level+1);
}

public:
    int deepestLeavesSum(TreeNode* root) {
        helper(root,1);
        return sum;
    }
};