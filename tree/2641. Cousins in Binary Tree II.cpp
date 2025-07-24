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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> ls;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            int sum = 0;
            while(s--){
                TreeNode *front = q.front();
                q.pop();
                sum+=front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ls.push_back(sum);
        }

        // s2 
        int i=1;
        queue<TreeNode*> q1;
        q1.push(root);
        while(!q1.empty()){
            int si = q1.size();
            while(si--){
                TreeNode *front = q1.front();
                q1.pop();
                int ss = (front->left ? front->left->val : 0) + (front->right ? front->right->val : 0);

                if(front->left){
                    front->left->val = ls[i]-ss;
                    q1.push(front->left);
                }
                if(front->right){
                    front->right->val = ls[i]-ss;
                    q1.push(front->right);
                }
            }
            i++;
        }
        root->val = 0;
        return root;
    }
};

// sol 2
class Solution {
    void solv(TreeNode*& root,  vector<int>& l, int level) {
        if (!root) return;

        int ss = 0;
        if (root->left) ss += root->left->val;
        if (root->right) ss += root->right->val;

        if (root->left) {
            root->left->val = l[level] - ss;
        }
        if (root->right) {
            root->right->val = l[level] - ss;
        }

        solv(root->left, l, level + 1);
        solv(root->right, l, level + 1);
    }

public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> ls;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int s = q.size();
            int sum = 0;

            for (int i = 0; i < s; ++i) {
                TreeNode* front = q.front();
                q.pop();

                sum += front->val;

                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }

            ls.push_back(sum);
        }

        root->val = 0;
        solv(root, ls, 1);
        return root;
    }
};
