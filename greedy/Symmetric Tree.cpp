/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
    
  bool dfs(Node *lp , Node *rp){
      if(!lp && !rp) return true;
      else if((!lp && rp) || (lp && !rp)) return false;
      else if(lp->data!=rp->data) return false;
    //   else return false;
      return dfs(lp->left,rp->right) && dfs(lp->right,rp->left);
      
      
  }    
  public:
    bool isSymmetric(Node* root) {
        // Code here
        return dfs(root->left,root->right);
    }
};