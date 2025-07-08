/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

    int pl = -1;
    void helper(TreeNode* root, vector<int>& res, int level) {
        if (!root) {
            return;
        }

        // cout << "val " << root->val << " level " << level << endl;
        if (level > pl) {
            pl = level;
            res.push_back(root->val);
        }
        if(level<res.size() && root->val>res[level]){
            res[level] = root->val;
        }
        level++;
        helper(root->left, res, level);
        helper(root->right, res, level);
    }

public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        helper(root, res, 0);
        return res;
    }
};