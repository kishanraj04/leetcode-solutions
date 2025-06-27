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

// bool check(TreeNode *h1 , TreeNode *h2) {
//     if (h1 == NULL && h2 == NULL) return true;
//     if (h1 == NULL || h2 == NULL) return false;
//     if (h1->val != h2->val) return false;

//     bool r1 = check(h1->left, h2->left);
//     bool r2 = check(h1->right, h2->right);
//     cout<<(r1&&r2)<<" ";
//     return r1&&r2;
// }


public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // return check(p,q);
        queue<TreeNode*> res;
        res.push(p);
        res.push(q);

        while(!res.empty()){
            TreeNode *f = res.front();
            res.pop();
            TreeNode *s = res.front();
            res.pop();

            if(f==NULL && s==NULL) continue;

            else if(f==NULL || s==NULL || f->val!=s->val) return false;

            res.push(f->left);
            res.push(s->left);
            res.push(f->right);
            res.push(s->right);
        }

        return true;
    }
};