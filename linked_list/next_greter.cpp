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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<int> s;
        ListNode *tmp = head, *prev = NULL, *curr = head, *n = head;

        // reverse list
        while (curr) {
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        tmp = prev;
        while (tmp) {
            if (s.empty()) {
                s.push(tmp->val);
                res.push_back(0);
            } else if (tmp->val < s.top()) {
                res.push_back(s.top());
                s.push(tmp->val);

            } else {
                while (!s.empty()) {
                    if (s.top() > tmp->val) {
                        res.push_back(s.top());
                        s.push(tmp->val);

                        break;
                    } else {
                        s.pop();
                    }
                }
                if (s.empty()) {
                    res.push_back(0);
                    s.push(tmp->val);
                }
            }

            tmp = tmp->next;
        }

       reverse(res.begin(),res.end());
        return res;
    }
};