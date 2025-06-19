class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        // solution 1
        // unordered_set<ListNode*> nodesInA;

        // // Store all nodes of list A
        // while (headA) {
        //     nodesInA.insert(headA);
        //     headA = headA->next;
        // }
         
        // // Check if any node in list B is already in set
        // while (headB) {
        //     if (nodesInA.find(headB) != nodesInA.end()) {
        //         return headB;  
        //     }
        //     headB = headB->next;
        // }

        // return NULL;  // No intersection

        // solution 2
        int countA = 0;
        int countB = 0;
        ListNode *tmpA = headA;
        ListNode *tmpB = headB;
        while(tmpA){
            countA++;
            tmpA=tmpA->next;
        }
        while(tmpB){
            countB++;
            tmpB=tmpB->next;
        }
        tmpA = headA;
        tmpB = headB;
        int diff = abs(countA-countB);

        // move the a or b at correct position
        while(diff){
            if(countA>countB){
                tmpA=tmpA->next;
            }else{
                tmpB=tmpB->next;
            }
            diff--;
        }

        // simultaneously move a and b
        while(tmpA && tmpB){
            if(tmpA==tmpB){
                return tmpA;
            }
            tmpA=tmpA->next;
            tmpB=tmpB->next;
        }

        return NULL;

    }
};
