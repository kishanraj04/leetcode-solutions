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

int maxFreq = INT_MIN;
vector<int> ans;
int helper(TreeNode* root, map<int, int>& res) {
    if (!root) return 0;

    int ls = helper(root->left, res);
    int rs = helper(root->right, res);

    int sum = root->val + ls + rs;
    res[sum]++;

    if (res[sum] > maxFreq) {
        maxFreq = res[sum];
        ans.clear();
        ans.push_back(sum);
    } else if (res[sum] == maxFreq) {
        ans.push_back(sum);
    }

    return sum;
}



public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int> res;
        helper(root,res);
        
        return ans;
        
    }
};