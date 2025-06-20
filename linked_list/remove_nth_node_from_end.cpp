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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* tmp = head;

        if (!head->next) {
            head = NULL;
            return head;
        }
        while (tmp) {
            count++;
            tmp = tmp->next;
        }
        int diff = count - n;
        tmp = head;
        ListNode* prev = NULL;
        // tmp at this node which you want to delete
        while (diff) {
            prev = tmp;
            tmp = tmp->next;
            diff--;
        }

        if(!diff && n==count){
            ListNode *d = head;
            head = head->next;
            delete d;
            return head;
        }
        ListNode *t = tmp;
        prev->next = tmp->next;
        delete tmp;
        
        return head;
    }
};