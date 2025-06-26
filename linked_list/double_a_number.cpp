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
    ListNode* doubleIt(ListNode* head) {
        ListNode *prev=NULL , *curr=head , *n=head;

        // reverse
        while(curr){
            n=curr->next;
            curr->next = prev;
            prev=curr;
            curr=n;
        }
        
        curr=prev;
        prev=NULL;
        int carry=0;
        while(curr){
            n=curr->next;
            int doub = (curr->val)*2 +carry;
            carry=doub/10;
            int num = doub%10;
            curr->val = num;
            curr->next = prev;
            prev = curr;
            curr=n;
        }

        if(carry>0){
            ListNode *cn = new ListNode(carry);
            cn->next=prev;
            prev=cn;
        }
        return prev;
    }
};