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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);
        ListNode *head = res;
        int carry = 0 , num=0;
        // traverse on both
        while(l1 && l2){
           
            int sum = (l1->val+l2->val)+carry;
            carry = sum/10;
            num = sum%10;
            ListNode *tmp = new ListNode(num);
            res->next = tmp;
            res = res->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        // travers on remaining
        if(!l1){
            while(l2){
                int sum = (l2->val)+carry;
                num = sum%10;
                carry = sum/10;
                res->next = new ListNode(num);
                res = res->next;
                l2 = l2->next;
            }
        }else{
            while(l1){
                int sum = (l1->val)+carry;
                num = sum%10;
                carry = sum/10;
                res->next = new ListNode(num);
                res = res->next;
                l1 = l1->next;
            }
        }
        if(carry) res->next=new ListNode(carry);
        return head->next;
    }
};