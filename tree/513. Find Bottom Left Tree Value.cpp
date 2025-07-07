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

int ans = 0;
int pl = 0;
int helper(TreeNode *root,int level){
    if(!root) return 0;
     
    if(level>pl){
        ans=root->val;
        pl = level;
    }
    level++;
    helper(root->left,level);
    
    helper(root->right,level);

    return ans;
}

public:
    int findBottomLeftValue(TreeNode* root) {
        if( !root->left && !root->right){
            return root->val;
        }
        return helper(root,1);
        
    }
};