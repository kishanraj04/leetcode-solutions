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
public:
    int maxLevelSum(TreeNode* root) {
        int level = 0;
        int sum = 0;
        int ms = INT_MIN;
        int ml = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int qs = q.size();
            level++;
            while(qs--){
                TreeNode *tmp = q.front();
                sum+=tmp->val;
                q.pop();

                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            if(sum>ms){
                ms=sum;
                ml=level;
            }
            sum=0;
        }

        return ml;
    }
};