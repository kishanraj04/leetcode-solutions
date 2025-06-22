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
        ListNode *prev=NULL,*curr=l1,*n=NULL;

        // reverse l1
        while(curr ){
            n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        l1=prev;
        
        // reverse l2
        curr=l2 , prev=NULL,n=NULL;
         while(curr){
            n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        
        l2=prev;
        int carry=0;
        int num=0;

        // traverse on both
        ListNode *res=new ListNode(0);
        ListNode *head=res;
        while(l1 && l2){
            cout<<"l1 "<<l1->val<<" "<<"l2 "<<l2->val<<endl;
            int sum = (l1->val+l2->val)+carry;
            num = sum%10;
            carry=sum/10;
            res->next=new ListNode(num);
            l1=l1->next;
            l2=l2->next;
            res=res->next;
        }

        // traverse on remainin
        if(l1){
            while(l1){
                int sum = l1->val+carry;
            int num = sum%10;
            carry = sum/10;
            res->next = new ListNode(num);
            l1=l1->next;
            res=res->next;
            }
        }else{
             while(l2){
            int sum = l2->val+carry;
            int num = sum%10;
            carry = sum/10;
            res->next = new ListNode(num);
            l2=l2->next;
            res=res->next;
            }
        }
        
        if(carry==1){
            res->next= new ListNode(1);
            res=res->next;
        }
        // rev res
        prev=NULL;
        curr=head->next;
        n=NULL;
        delete head;

        while(curr){
            n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        
        return prev;
    }
};