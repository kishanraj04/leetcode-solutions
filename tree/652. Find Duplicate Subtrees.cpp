class Solution {
    map<string, int> mm;
    vector<TreeNode*> res;

    string helper(TreeNode *root) {
        if (!root) return "n";

        string ls = helper(root->left);
        string rs = helper(root->right);
        string ns = to_string(root->val) + "," + ls + "," + rs;
        cout<<ns<<endl;
        if (mm[ns]++ == 1) {
            res.push_back(root);
        }

        return ns; 
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);
        return res;
    }
};
