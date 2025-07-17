class Solution {
    long maxProd = 0;
    long totalSum = 0;
    const int MOD = 1e9 + 7;

    long getTotal(TreeNode* root) {
        if (!root) return 0;
        return root->val + getTotal(root->left) + getTotal(root->right);
    }

    long dfs(TreeNode* root) {
        if (!root) return 0;
        long left = dfs(root->left);
        long right = dfs(root->right);
        long currSum = root->val + left + right;
        maxProd = max(maxProd, currSum * (totalSum - currSum));
        return currSum;
    }

public:
    int maxProduct(TreeNode* root) {
        totalSum = getTotal(root);
        dfs(root);
        cout<<maxProd % MOD;
        return maxProd % MOD; 
    }
};
