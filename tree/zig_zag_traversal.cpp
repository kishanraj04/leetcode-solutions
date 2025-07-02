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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        if(!root) return {};
        while(!q.empty()){
            int s = q.size();
            vector<int> tmp;

            while(s--){
                TreeNode *f = q.front();
                q.pop();
               
                     tmp.push_back(f->val);
                    if(f->left) q.push(f->left);
                    if(f->right) q.push(f->right);
                
               
            }
            res.push_back(tmp);
        }

        for(int i=0;i<res.size();i++){
            if(i%2!=0){
                reverse(res[i].begin(),res[i].end());
            }
        }
        return res;
    }
};