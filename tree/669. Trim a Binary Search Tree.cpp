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

int l = 0;
int h = 0;
TreeNode *pn = NULL;
TreeNode* helper(TreeNode* root) {
    if (!root) return nullptr;

    if (root->val < l)
    {
        return helper(root->right);}

    if (root->val > h)
        return helper(root->left);

    root->left = helper(root->left);
   
    root->right = helper(root->right);
    return root;
}



public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        l = low;
        h = high;
        return helper(root);
    }
};


// sol 2

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

int l = 0;
int h = 0;
TreeNode *pn = NULL;
TreeNode* helper(TreeNode* root) {
    if (!root) return nullptr;

    root->left = helper(root->left);
   
    root->right = helper(root->right);

    if(root->val<l){
        return root->right;
    }
    if(root->val>h){
        return root->left;
    }
    return root;
}



public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        l = low;
        h = high;
        return helper(root);
    }
};