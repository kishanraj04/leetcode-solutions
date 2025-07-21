class Solution {
    unordered_map<int, TreeNode*> parentMap;
    TreeNode* infected = NULL;
    int s = 0;

    void inord(TreeNode* root, TreeNode* parent) {
        if (!root) return;
        if (root->val == s) infected = root;

        inord(root->left, root);
        parentMap[root->val] = parent;
        inord(root->right, root);
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        s = start;
        inord(root, nullptr);

        queue<TreeNode*> q;
        q.push(infected);
        int ic = 0;
        unordered_set<int> visited;
        visited.insert(start);

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* front = q.front();
                q.pop();

                if (front->left && visited.count(front->left->val) == 0) {
                    q.push(front->left);
                    visited.insert(front->left->val);
                }

                if (front->right && visited.count(front->right->val) == 0) {
                    q.push(front->right);
                    visited.insert(front->right->val);
                }

                if (parentMap[front->val] &&
                    visited.count(parentMap[front->val]->val) == 0) {
                    q.push(parentMap[front->val]);
                    visited.insert(parentMap[front->val]->val);
                }
            }
            ic++;
        }
        return ic - 1;
    }
};
