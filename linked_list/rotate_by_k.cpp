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
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 0;
        ListNode *tmp=head , *curr=head,*prev=NULL;
        if(!head || !head->next){
            return head;
        }
        while(tmp){
            count++;
            tmp=tmp->next;
        }

        int move = k%count;
        tmp=head;
        int diff = count-move;

        // check for count and k
        if (move == 0) return head;

        // move tmp at kth node
        while(diff){
            prev = curr;
            curr=curr->next;
            diff--;
        }
        
        // null at kth-1
        prev->next=NULL;
        tmp = curr;
        while(tmp && tmp->next){
            tmp=tmp->next;
        }
        tmp->next=head;
        return curr;

    }
};