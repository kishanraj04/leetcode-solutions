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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow=head , *fast=head , *prev=NULL;

        if(!head->next){
            return head->next;
        }
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(!slow->next){
            prev->next=NULL;
            return head;
        }else{
            prev->next = slow->next;
            return head;
        }

        return head;
    }
};