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

int findIdx(vector<int> iod , int target , int s , int e){
    for(int i=s;i<=e;i++){
        if(iod[i]==target) return i;
    }
    return -1;
}

TreeNode* create(vector<int> pre , vector<int> in , int si , int ei , int idx){
     if(si>ei) return NULL;
     TreeNode *root = new TreeNode(pre[idx]);
     int pos = findIdx(in , pre[idx] , si ,ei);
     root->left = create(pre,in,si,pos-1,idx+1);
     root->right = create(pre,in,pos+1,ei,idx+(pos-si)+1);

     return root;
}

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return create(preorder,inorder,0,preorder.size()-1,0);
    }
};


// sol 2

class Solution {
    unordered_map<int, int> inMap; // value -> index in inorder
    int preIdx = 0;

    TreeNode* create(const vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);

        int inRootIdx = inMap[rootVal];

        root->left = create(preorder, inStart, inRootIdx - 1);
        root->right = create(preorder, inRootIdx + 1, inEnd);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inMap.clear();
        preIdx = 0;

        // Map all inorder values to their indices
        for (int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }

        return create(preorder, 0, inorder.size() - 1);
    }
};
