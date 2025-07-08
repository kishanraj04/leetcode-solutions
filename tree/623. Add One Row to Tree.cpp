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
    int value = 0;
    int d = 1;

    void addRow(TreeNode* root, int level) {
        if (!root) return;

        if (level == d - 1) {
            // Insert new nodes
            TreeNode* newLeft = new TreeNode(value);
            TreeNode* newRight = new TreeNode(value);

            newLeft->left = root->left;
            newRight->right = root->right;

            root->left = newLeft;
            root->right = newRight;
            return;
        }

        addRow(root->left, level + 1);
        addRow(root->right, level + 1);
    }

public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        value = val;
        d = depth;

        // Special case when new row is to be added at the root
        if (d == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        addRow(root, 1);
        return root;
    }
};
