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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int rs = 0, re = m - 1, cs = 0, ce = n - 1;
        ListNode* tmp = head;

        while (rs <= re && cs <= ce && tmp) {
            // Top row
            for (int i = cs; i <= ce && tmp; i++) {
                res[rs][i] = tmp->val;
                tmp = tmp->next;
            }
            rs++;

            // Right column
            for (int i = rs; i <= re && tmp; i++) {
                res[i][ce] = tmp->val;
                tmp = tmp->next;
            }
            ce--;

            // Bottom row
            for (int i = ce; i >= cs && tmp; i--) {
                res[re][i] = tmp->val;
                tmp = tmp->next;
            }
            re--;

            // Left column
            for (int i = re; i >= rs && tmp; i--) {
                res[i][cs] = tmp->val;
                tmp = tmp->next;
            }
            cs++;
        }

        return res;
    }
};
