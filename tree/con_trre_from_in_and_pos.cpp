class Solution {
    unordered_map<int, int> inorderMap;
    int postIdx;

    TreeNode* build(const vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inorderMap[rootVal];

        root->right = build(postorder, inIndex + 1, inEnd);
        root->left = build(postorder, inStart, inIndex - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        postIdx = n - 1;

        for (int i = 0; i < n; ++i)
            inorderMap[inorder[i]] = i;

        return build(postorder, 0, n - 1);
    }
};
