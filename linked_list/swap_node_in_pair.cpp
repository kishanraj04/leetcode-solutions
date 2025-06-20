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
    ListNode* swapPairs(ListNode* head) {
        int count=1;
        ListNode *curr = head;
        if(!head){
            return head;
        }else{
            while(curr){
                if(count%2!=0 && curr->next){
                    swap(curr->val,curr->next->val);
                }
                curr = curr->next;
                count++;
            }
        }
        return head;
    }
};