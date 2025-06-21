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
    void reorderList(ListNode* head) {
        // solution 1
        //    map<int,int> m;
        //    ListNode *tmp = head;
        //    int count=0;
        //    while(tmp){
        //     m[count++]=tmp->val;
        //     tmp=tmp->next;
        //    }
        //    tmp=head;

        //    int ci=0;
        //    int idx=count-1;
        //    int tc=0;
        //    while(tc!=count){
        //     if(tc%2!=0){
        //         tmp->val=m[idx--];
        //     }
        //     else{
        //         tmp->val=m[ci++];
        //     }
        //     tc++;
        //     tmp=tmp->next;
        //    }

        // solution 2
        if (!head || !head->next) return;

        // Step 1: Find the middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        slow->next = nullptr; // Important: cut the list

        // Step 3: Merge both halves
        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};