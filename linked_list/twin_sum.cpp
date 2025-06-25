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
    int pairSum(ListNode* head) {
        ListNode *slow=head , *fast=head , *prev=NULL , *curr=NULL , *n=NULL;

        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        } 

        prev->next=NULL;
        prev=NULL;
        while(slow){
            n=slow->next;
            slow->next=prev;
            prev=slow;
            slow=n;
        }

        ListNode *tmp1=head,*tmp2=prev;
        int ts=-1;
        while(tmp1 && tmp2){
            int sum = tmp1->val+tmp2->val;
            ts=max(ts,sum);
            tmp1=tmp1->next;
            tmp2=tmp2->next;
        }
        return ts;
    }
};