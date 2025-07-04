/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            Node* prev = NULL;
            bool flag = true;
            while(s--){
                Node *f = q.front();
                q.pop();
                if(flag){
                    f->next = NULL;
                    flag = false;
                }else{
                    f->next = prev;
                }
                prev = f;
                if(f->right) q.push(f->right);
                if(f->left) q.push(f->left);
            }
        }
        return root;
    }
};