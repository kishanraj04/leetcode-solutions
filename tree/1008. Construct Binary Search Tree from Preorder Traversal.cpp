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
int i = 0;
TreeNode* helper(vector<int> pre,int min , int max){
    if(i>=pre.size()) return nullptr;
    int val = pre[i];
    if(val<min || val>max) return nullptr;

    TreeNode *node = new TreeNode(val);
    i++;
    node->left = helper(pre,min,val);
    node->right = helper(pre,val,max);

    return node;
    
}

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       return helper(preorder,INT_MIN,INT_MAX);
    }
};