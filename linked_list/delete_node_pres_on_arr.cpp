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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s;
        for(int v:nums){
            s.insert(v);
        }
        
        ListNode *curr=head;
        ListNode *res = new ListNode(0);
        ListNode *t = res;
        while(curr){
            if(!(s.find(curr->val)!=s.end())){
                res->next=new ListNode(curr->val);
                res=res->next;
            }
            curr=curr->next;
        }

        return t->next;
    }
};