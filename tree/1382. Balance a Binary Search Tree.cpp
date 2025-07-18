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

vector<int> ino;
void inorder(TreeNode*root){
    if(!root) return;

    inorder(root->left);
    ino.push_back(root->val);
    inorder(root->right);

    // return ino;
}


TreeNode * build(int s , int e){
       if(s>e) return nullptr;
       int mid = s+(e-s)/2;
       TreeNode *root = new TreeNode(ino[mid]);
    
       root->left = build(s,mid-1);
       root->right = build(mid+1,e);

       return root; 
}

public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(0,ino.size()-1);
    }
};