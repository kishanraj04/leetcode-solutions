class Solution {
    void dfs(TreeNode* root, int minVal, long &secondMin) {
        if (!root) return;

        if (root->val > minVal && root->val < secondMin) {
            secondMin = root->val;
        }
        dfs(root->left, minVal, secondMin);
        dfs(root->right, minVal, secondMin);
    }

public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;

        int minVal = root->val;
        long secondMin = LONG_MAX; 

        dfs(root, minVal, secondMin);

        return (secondMin == LONG_MAX) ? -1 : secondMin;
    }
};
