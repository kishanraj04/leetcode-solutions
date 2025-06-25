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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *res = new ListNode(0);
        ListNode *tmp = head->next , *nh=res;
        int sum=0;
        while(tmp){
            if(tmp->val==0){
                ListNode *s = new ListNode(sum);
                res->next=s;
                res=res->next;
                sum=0;
            }else{
                sum+=tmp->val;
            }
            tmp=tmp->next;
        }

        return nh->next;
    }
};