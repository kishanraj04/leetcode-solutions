// sol 1

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
int sum = 0;
void helper(TreeNode *root){
    if(!root) return;
    
    if(root->val%2==0){
        if(root->left){
            if(root->left->left){
                sum+=root->left->left->val;
                
            }
            if(root->left->right){
                    sum+=root->left->right->val;
                }
        }
        if(root->right){
            if(root->right->left){
                sum+=root->right->left->val;
            }
            if(root->right->right){
                sum+=root->right->right->val;
            }

        }
    }

    helper(root->left);
    helper(root->right);
}

public:
    int sumEvenGrandparent(TreeNode* root) {
        helper(root);
        return sum;
    }
};


// sol 2
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
int sum = 0;
void helper(TreeNode *root,TreeNode *p , TreeNode *gp){
    if(!root) return;
    
    if(gp && gp->val%2==0){
        sum+=root->val;
    }

    helper(root->left,root,p);
    helper(root->right,root,p);
    
}

public:
    int sumEvenGrandparent(TreeNode* root) {
        helper(root,nullptr,nullptr);
        return sum;
    }
};