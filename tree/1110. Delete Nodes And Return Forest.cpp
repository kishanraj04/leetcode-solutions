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

vector<TreeNode*> res;

TreeNode* helper(TreeNode* &root, vector<int> &to) {
    if (!root) return nullptr;

    root->left = helper(root->left, to);
    root->right = helper(root->right, to);

    if (find(to.begin(), to.end(), root->val) != to.end()) {
        if (root->left) res.push_back(root->left);
        if (root->right) res.push_back(root->right);
        return nullptr;
    }

    return root;
}

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        helper(root,to_delete);
        if(find(to_delete.begin(),to_delete.end(),root->val)==to_delete.end()){
            res.push_back(root);
        }
        return res;
    }
};