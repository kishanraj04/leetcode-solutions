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
void isSame1(TreeNode* r1,vector<int> &res1) {
    if (!r1 ) return;
    
    if(!r1->left && !r1->right){
        res1.push_back(r1->val);
    }

    isSame1(r1->left,res1);
    isSame1(r1->right,res1);
    
}

void isSame2(TreeNode* r2,vector<int> &res2) {
    if (!r2 ) return;
    
    if(!r2->left && !r2->right){
        res2.push_back(r2->val);
    }

    isSame2(r2->left,res2);
    isSame2(r2->right,res2);
    
}
 

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1;
        vector<int> res2;
        
        isSame1(root1,res1);
        isSame2(root2,res2);

        return res1==res2;

    }
};