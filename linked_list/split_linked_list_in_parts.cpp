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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        int count = 0;
        ListNode *tmp = head , *prev=NULL , *curr=head,*n=head;
        while(tmp){
            count++;
            tmp=tmp->next;
        }
        
        if(k>count){
            tmp=head;
            int idx=0;
            while(tmp){
                res.push_back(new ListNode(tmp->val));
                tmp=tmp->next;
                idx++;
            }
            for(int i=0;i<(k-idx);i++){
                res.push_back(nullptr);
            }
            return res;
        }

        int avg = count/k;
        int e = count%k;
        while(n){
            for(int i=0;i<avg;i++){
                prev = n;
                n=n->next;
            }
        
            if(e>0){
                prev=n;
                n=n->next;
                e--;
            }

            // if(k<count){
            //      cout<<"v "<<prev->val<<curr->val<<n->val;
            // }
            prev->next=NULL;
            res.push_back(curr);
            curr=n;
            // if(curr){
            //     cout<<"c "<<curr->val;
            // }
        }

        return res;
        
    }
};