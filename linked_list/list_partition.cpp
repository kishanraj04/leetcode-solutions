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
    ListNode* partition(ListNode* head, int x) {
        ListNode *res = new ListNode(0);
        ListNode *front = res;
        ListNode *tmp = head;

        // num less than x
        while(tmp){
            if(tmp->val<x){
                res->next = new ListNode(tmp->val);
                res=res->next;
            }
            tmp=tmp->next;
            
        }

        // num >= x
        tmp=head;
        while(tmp){
           if(tmp->val>=x){
            res->next = new ListNode(tmp->val);
              res=res->next;
           }
         
           tmp=tmp->next;
        }

        return front->next;
    }
};