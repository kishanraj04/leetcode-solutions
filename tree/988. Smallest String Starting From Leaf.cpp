class Solution {
    string smallest = "~"; // Initialize with a high lexicographic value

    void dfs(TreeNode* node, string path) {
        if (!node) return;

        // Add current character to path (prepend because it's leaf to root)
        path = char('a' + node->val) + path;

        if (!node->left && !node->right) {
            // At leaf node, update smallest if needed
            if (path < smallest) {
                smallest = path;
            }
        }

        dfs(node->left, path);
        dfs(node->right, path);
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return smallest;
    }
};
