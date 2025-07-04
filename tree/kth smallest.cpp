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

int kth = 0;
void helper(TreeNode *root,int &c,int &num){
    if(!root) return;

    helper(root->left,c,num);
    c++;
    if(c==kth){
        num=root->val;
        return;
    }
    helper(root->right,c,num);
}

public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int num = 0;
        kth=k;
        helper(root,count,num);
        return num;
    }
};