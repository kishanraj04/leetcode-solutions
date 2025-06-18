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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head;
        ListNode *prev = NULL;
        int dup = 200;
        if( head==NULL || !head->next){
            return head;
        }
        while(curr){
            if(curr->val==dup){
                ListNode *tmp = curr;
                prev->next = curr->next;
                curr=curr->next;
                delete tmp;
            }else{
                prev=curr;
                curr=curr->next;
            }
            dup = prev->val;
        }
        return head;
    }
};