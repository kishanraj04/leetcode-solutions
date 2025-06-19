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
    bool hasCycle(ListNode *head) {
    //    solution 1
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;

    // solution 2
    //    map<ListNode*,int> mm;
    //    ListNode *tmp=head;
    //    while(tmp){
    //     if(mm.find(tmp->next) !=mm.end()){
    //         return true;
    //     }else{
    //         mm[tmp->next]=tmp->val;
    //     }
    //     tmp=tmp->next;
    //    }
    //    return false;
    } 
};