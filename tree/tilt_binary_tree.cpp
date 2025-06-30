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

int helper(TreeNode *root,int &sum){
    if(!root) return 0;

    int lv = helper(root->left,sum);
    int rv = helper(root->right,sum);

    int ad = abs(lv-rv);
    int v = root->val+lv+rv;
    root->val = ad;
    if(root->left || root->right){
        sum+=root->val;
    }
    return v;
}

public:
    int findTilt(TreeNode* root) {
        int sum =0;
        helper(root,sum);
        return sum;    
    }
};