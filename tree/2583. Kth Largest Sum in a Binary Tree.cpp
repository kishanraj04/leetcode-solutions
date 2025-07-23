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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> levelSum;
        while(!q.empty()){
            long long s = q.size();
            long long sum = 0;
            while(s--){
                TreeNode *front = q.front();
                q.pop();
                sum+=front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            levelSum.push_back(sum);

        }

        // find max sum;
        sort(levelSum.begin(),levelSum.end());
        long long idx = levelSum.size()-k;
        if(idx>=levelSum.size() || idx<0) return -1;
        return levelSum[idx];
    }
};