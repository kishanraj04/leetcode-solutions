class Solution {
    int mp = -1;
    void helper(TreeNode* node, bool direction,int steps) {
        if (!node) return;

        mp = max(mp,steps);

        if (direction)
           { helper(node->left,false,steps+1);
             helper(node->right,true,1);             
           } 
        else
           { helper(node->right,true,steps+1);
             helper(node->left,false,1);
           } 
    }

public:
    int longestZigZag(TreeNode* root) {
        if (!root) return 0;

        cout << "Start left: ";
        helper(root, true,0);

        return mp; // Currently just printing the pattern
    }
};
