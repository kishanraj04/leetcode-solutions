#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int totalOps = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<int> levelValues;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelValues.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            totalOps += countMinSwaps(levelValues);
        }

        return totalOps;
    }

    int countMinSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }

        sort(arr.begin(), arr.end());
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || arr[i].second == i)
                continue;

            int cycle_size = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cycle_size++;
            }

            if (cycle_size > 1)
                swaps += cycle_size - 1;
        }

        return swaps;
    }
};
