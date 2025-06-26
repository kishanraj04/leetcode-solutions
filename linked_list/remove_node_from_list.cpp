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
    ListNode* removeNodes(ListNode* head) {
        ListNode *prev=NULL , *curr=head , *n=NULL;

        // reverse
        while(curr){
            n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        curr=prev->next;
        ListNode *res = prev;
        while(curr){
            if(curr->val<prev->val){
                prev->next = curr->next;
                curr=NULL;
                curr=prev->next;

            }else{
                prev=curr;
                curr=curr->next;
                
            }
        }
        prev=NULL,curr=res,n=NULL;
        while(curr){
            n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        return prev;
    }
};