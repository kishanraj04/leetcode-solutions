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
    int findGCD(int a, int b){
        if(b==0) return a;

        return gcd(b,a%b);
    }

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *curr=head , *n = head;

        if(!head->next){
            return head;
        }

        while(curr->next){
            n=curr->next;
            int gcd = findGCD(curr->val,n->val);
            ListNode *g = new ListNode(gcd);
            curr->next=g;
            g->next=n;
            curr=n;
            n=n->next;
        }

        return head;
    }
};