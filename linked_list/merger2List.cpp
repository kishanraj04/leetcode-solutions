class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode(0);
        ListNode *tail = head;

        while(list1 && list2){
            if(list1->val<=list2->val){
                tail->next = list1;
                tail=tail->next;
                list1=list1->next;
            }else{
                tail->next = list2;
                tail=tail->next;
                list2=list2->next;
            }
            
        }

        if(!list1){
            tail->next=list2;
        }else{
            tail->next=list1;
        }
        
       

        return head->next;
    }
};
