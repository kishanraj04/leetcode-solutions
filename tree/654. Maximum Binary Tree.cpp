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

TreeNode *build(vector<int> nums , int s , int e){
    if(s>e) return NULL;

    // find max
    int mv = INT_MIN;
    int mvi = s;
    for(int i=s;i<=e;i++){
        if(mv<nums[i]){
            mv = nums[i];
            mvi = i;
        }
    }
    TreeNode* root = new TreeNode(nums[mvi]);
    cout<<"s "<<s<<" e "<<e<<" m "<<mvi<<endl;
    root->left = build(nums,s,mvi-1);
    //  cout<<"s "<<s<<" e "<<e;
    root->right = build(nums,mvi+1,e);

    return root;
}

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
};