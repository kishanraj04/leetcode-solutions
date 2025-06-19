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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL , *curr=head , *nn=NULL;
        if(!head || !head->next){
            return head;
        }
        nn = curr->next;
        while(curr){
            curr->next = prev;
            prev = curr;
            curr=nn;
            if(nn) nn=nn->next;
        }

        return prev;
    }
};