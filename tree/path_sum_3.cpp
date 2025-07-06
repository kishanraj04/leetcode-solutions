class Solution {
public:
    int count = 0;

    void dfs(TreeNode* root, long long currSum, int targetSum) {
        if (!root) return;

        currSum += root->val;
        if (currSum == targetSum) count++;

        dfs(root->left, currSum, targetSum);
        dfs(root->right, currSum, targetSum);
    }

    void traverse(TreeNode* root, int targetSum) {
        if (!root) return;

        dfs(root, 0, targetSum);  
        traverse(root->left, targetSum); 
        traverse(root->right, targetSum); 
    }

    int pathSum(TreeNode* root, int targetSum) {
        count = 0;
        traverse(root, targetSum);
        return count;
    }
};
