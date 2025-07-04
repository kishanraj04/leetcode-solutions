class Solution {
    void helper(TreeNode* root, int sum, int target, vector<vector<int>> &res, vector<int> tmp) {
        if (!root) return;

        tmp.push_back(root->val);
        sum += root->val;

        if (!root->left && !root->right && sum == target) {
            res.push_back(tmp);
        }

        helper(root->left, sum, target, res, tmp);
        helper(root->right, sum, target, res, tmp);
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> tmp;
        helper(root, 0, targetSum, res, tmp);
        return res;
    }
};
