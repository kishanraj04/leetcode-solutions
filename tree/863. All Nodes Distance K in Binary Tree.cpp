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

unordered_map<TreeNode*,TreeNode *> m;

void inorder(TreeNode *root){
    if(!root) return;
    
    if(root->left){
        m[root->left] = root;
    }

    if(root->right){
        m[root->right] = root;
    }
    inorder(root->left);
    inorder(root->right);
}


public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        inorder(root);
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<int> visited;
        int level = 0;
        visited.insert(target->val);
        while(!q.empty()){
            int s = q.size();
            level++;
            if(level==k+1){
                break;
            }
            while(s--){
                TreeNode* f = q.front();
                visited.insert(f->val);
                q.pop();

                if(f->left && visited.count(f->left->val)<=0){
                    q.push(f->left);
                    visited.insert(f->left->val);
                }

                 if(f->right && visited.count(f->right->val)<=0){
                    q.push(f->right);
                    visited.insert(f->right->val);
                }

                if(m.find(f)!=m.end() && visited.count(m[f]->val)<=0){
                    q.push(m[f]);
                    visited.insert(m[f]->val);
                }
                
            }
        }

        vector<int> res;
        while(!q.empty()){
            TreeNode *tmp = q.front();
            q.pop();
            res.push_back(tmp->val);
        }

        return res;
    }
};