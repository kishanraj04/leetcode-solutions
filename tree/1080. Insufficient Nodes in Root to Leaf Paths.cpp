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
TreeNode* helper(TreeNode* &root,int limit,int sum){
    if(!root) return NULL;
    
    sum+=root->val;
    if(!root->left && !root->right){
        return sum>=limit?root:NULL; 
    }
    
    cout<<root->val<<" "<<sum<<endl;
    root->left = helper(root->left,limit,sum);
    root->right = helper(root->right,limit,sum);

    return !root->left&&!root->right?NULL:root;

}
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        
        TreeNode *tmp = root;
        return helper(root,limit,0);
    }
};