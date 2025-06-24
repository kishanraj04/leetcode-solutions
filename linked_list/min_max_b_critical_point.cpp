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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *tmp=head;
        int count = 0;
        int lic = 1;
        vector<int> dist;
        // check for 2 element
        if(!head->next->next){
            return {-1,-1};
        }

    
// finding the index of last critical ele..
        ListNode *curr=head,*prev=NULL,*n=head->next,*dummy=NULL;
        int idx=1;
        while(n->next){
            prev=curr;
            curr=n;
            n=n->next;
            idx++;
            if((curr->val<n->val && curr->val<prev->val) || (curr->val>n->val && curr->val>prev->val))
            {
                dist.push_back(idx);
            }
        }
      
       sort(dist.begin(),dist.end());
       int max = 0;
       int mv = INT_MAX;

       if(dist.size()==1 || dist.size()==0){
        return {-1,-1};
       }else{
        
    // int maxDist = abs(dist[0] - dist[dist.size() - 1]);
    int minDiff = INT_MAX;
    max = abs(dist[0]-dist[dist.size()-1]);
    for (int i = 0; i < dist.size() - 1;i++) {
        int md =abs( dist[i]-dist[i+1]);
        mv = min(mv,md);
    }

       }

    return {mv,max};

    }
};