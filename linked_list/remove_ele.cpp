/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        bool isflag = true , flag=true;
        if(!head ){
            return head;
        }else if(!head->next){
            if(head->val==val){
                head=NULL;
                return head;
            }else{
                return head;
            }
        }
        else{
            ListNode *curr = head;
            ListNode *prev = new ListNode(0);
            while(curr){
                int dup = curr->val;
                if(dup!=val){
                    prev = curr;
                    curr = curr->next;
                    flag=false;
                }else{
                    while(curr && dup==curr->val){
                        curr=curr->next;
                    }
                    prev->next = curr;
                    if(isflag && flag){
                        head=prev->next;
                    }
                    isflag=false;
                }
            }
            
        }
        return head;
    }
};