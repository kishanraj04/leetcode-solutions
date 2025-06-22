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
#include <cstdlib>  // for rand()
#include <ctime>    // for seeding rand()

class Solution {
    int count = 0;
    ListNode* head;
    
public:
    Solution(ListNode* head) {
        this->head = head;
        ListNode* tmp = head;
        while (tmp) {
            count++;
            tmp = tmp->next;
        }
       
    }
    
    int getRandom() {
        int ri = rand() % count; // random index in [0, count-1]
        ListNode* tmp = head;
        for (int i = 0; i < ri; i++) {
            tmp = tmp->next;
        }
        return tmp->val;
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */