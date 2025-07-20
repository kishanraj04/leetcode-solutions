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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> m;
        unordered_set<int> c;

        for(int i=0;i<descriptions.size();i++){
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];

            if(m.find(parent)==m.end()){
                m[parent] = new TreeNode(parent);
            }
            if(m.find(child)==m.end()){
                m[child] = new TreeNode(child);
            }

            if(isLeft){
                m[parent]->left = m[child];
            }else{
                m[parent]->right = m[child];
            }
            
        c.insert(child);
        }

        for(int p=0;p<descriptions.size();p++){
            if(c.find(descriptions[p][0])==c.end()){
                return m[descriptions[p][0]];
            }
        }

        return nullptr;
    }
};