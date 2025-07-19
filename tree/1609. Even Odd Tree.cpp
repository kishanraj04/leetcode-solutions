class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = -1;
        int prev = 0;

        while (!q.empty()) {
            int s = q.size();
            level++;
            prev = (level % 2 == 0) ? INT_MIN : INT_MAX;

            while (s--) {
                TreeNode* front = q.front();
                q.pop();

                if (level % 2 == 0) {
                    if (front->val % 2 == 0 || front->val <= prev)
                        return false;
                } else {
                    if (front->val % 2 != 0 || front->val >= prev)
                        return false;
                }

                prev = front->val;

                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
            prev = 0;
        }

        return true;
    }
};
