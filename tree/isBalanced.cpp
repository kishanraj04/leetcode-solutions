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
int check(TreeNode* h, bool& isb, int& m) {
    if (h == NULL) return 0;

    int lh = check(h->left, isb, m);
    int rh = check(h->right, isb, m);

    // Update max height
    m = max(m, 1 + max(lh, rh));

    if (abs(lh - rh) > 1) {
        isb = false;
    }

    return 1 + max(lh, rh); 
}


public:
    bool isBalanced(TreeNode* root) {
        bool isb = true;
        int m =0;
        check(root,isb,m);
        return isb;
    }
};