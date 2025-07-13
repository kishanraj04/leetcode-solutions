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
    int total = 0;

    int cn(TreeNode*root){
        if(!root) return 0;

        return 1+cn(root->left)+cn(root->right);
    }

    bool countNodesUpToLevel(TreeNode* root, int index,int tn) {
        if (!root) return true;

        
        if(index>tn){
            return false;
        }
    cout<<root->val<<" "<<index<<endl;
       return countNodesUpToLevel(root->left, 2 * index,tn) &&
        countNodesUpToLevel(root->right, 2 * index + 1,tn);
    }

public:
    bool isCompleteTree(TreeNode* root) {
        // if(!root->left && !root->right) return true;
        int tn = cn(root);
       return countNodesUpToLevel(root, 1,tn);
       
    }
};
