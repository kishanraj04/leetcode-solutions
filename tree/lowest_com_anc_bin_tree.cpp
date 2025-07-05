/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {

    int p1 = 0;
    int q1 = 0;
    int count = 0;
    TreeNode* helper(TreeNode* root) {
        if (!root)
            return nullptr;

        if (root && (root->val == p1 || root->val==q1)){
            return root;
        }

        TreeNode *l = helper(root->left);
        TreeNode *r =  helper(root->right);

        if(l && r){
            cout<<l->val<<" "<<r->val<<" "<<endl;
        }

        if(l&&r){
            return root;
        }
        return l?l:r;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
        p1=p->val;
        q1=q->val;
        return helper(root);
    }
};