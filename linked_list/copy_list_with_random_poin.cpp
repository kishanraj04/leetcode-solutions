/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node  *oh=head , *tail=NULL;
        map<Node* , Node*> mm;
        
        // if head is not exist
        if(!head){
            return head;
        }
        Node *nh = new Node(oh->val);
        tail=nh;
        mm[oh]=nh;
        oh=oh->next;
        while(oh){
            tail->next=new Node(oh->val);
            tail=tail->next;
            mm[oh]=tail;
            oh=oh->next;
            
        }
        // iterate on original and create another list
        oh=head;
        tail=nh;
        while(tail){
            tail->random = mm[oh->random];
            tail=tail->next;
            oh=oh->next;
        }

        return nh;

    }
};