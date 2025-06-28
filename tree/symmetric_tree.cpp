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

// void checkSame(TreeNode *l , TreeNode *r , bool &flag){
//         if(l==NULL || r==NULL){
//             flag = (l==r) && flag;
//             return;
//         }
//         else if(l->val!=r->val){
//             flag = false;
//         }
//         cout<<l->val<<" "<<r->val<<" ";
//         checkSame(l->left,r->right,flag);
//         checkSame(l->right,r->left,flag);
// }

public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;

        q1.push(root);
        q2.push(root);

        while(!q1.empty() || !q2.empty()){
            TreeNode *qv1 = q1.front();
            q1.pop();
            TreeNode *qv2 = q2.front();
            q2.pop();
            if((!qv1  && qv2) || (!qv2 && qv1)){
                return false;
            }
            if(!qv1 && !qv2){
                continue;
            }

            if(qv1->val!=qv2->val){
                return false;
            }
            q1.push(qv1->left);
            q1.push(qv1->right);

            q2.push(qv2->right);
            q2.push(qv2->left);
        }
        return true;
    }
};