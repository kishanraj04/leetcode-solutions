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

int count = 0;
pair<int,int> solv(TreeNode *root){
    if(!root) return {0,0};
    
    auto left = solv(root->left);
    auto right = solv(root->right);
    
    int sum = left.second+right.second+root->val;
    int node = left.first+right.first+1;
    int d = sum/node;
    if(d==root->val){
        count++;
    }
    return {node,sum};
}

public:
    int averageOfSubtree(TreeNode* root) {
         solv(root);

         return count;
    }
};