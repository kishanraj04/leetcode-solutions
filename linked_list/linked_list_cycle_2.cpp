/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {

        // solution 1
        // set<ListNode*> v;
        // ListNode *tmp = head;

        // if(!head){
        //     return nullptr;
        // }else if(!head->next){
        //     return head->next;
        // }

        // while(tmp){
        //     if(v.find(tmp)!=v.end()){
        //         return tmp;
        //     }
        //     v.insert(tmp);
        //     tmp=tmp->next;

        // }

        // return nullptr;
        if (!head) {
            return nullptr;
        } else if (!head->next) {
            return head->next;
        }

        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                fast =
                    head;
                while(fast){
                    if(fast==slow){
                        return fast;
                    }
                    slow=slow->next;
                    fast=fast->next;
                }
                // return fast;
            }
        }

     
        return nullptr;
    }
};