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

int maxD(TreeNode *head,int md){
    if(head==NULL) return 0;

    int lh = maxD(head->left,md);
    int rh = maxD(head->right,md);
    md =1+max(lh,rh);
    return md;
}

public:
    int maxDepth(TreeNode* root) {
        int md = 0;
        md = maxD(root , md);
        return md;
    }
};