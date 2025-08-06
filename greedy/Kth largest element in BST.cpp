/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
    int kth = 0;
    int curr =0;
    int res = 0;
    void dfs(Node *root){
        if(!root) return ;
       
      
        
        dfs(root->right);
        curr++;
         if(curr==kth) {
            res=root->data;
            return;
        };
        dfs(root->left);
        
    }
  public:
    int kthLargest(Node *root, int k) {
        // Your code here
        kth=k;
         dfs(root);
         return res;
    }
};