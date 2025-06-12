class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0; 

        int cp = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            long long target = (long long)nums[i] + k;

            int s = i + 1;
            int e = nums.size() - 1;
            while (s <= e) {
                int m = (s + e) / 2;
                if (nums[m] == target) {
                    cp++;
                    break; 
                } else if (nums[m] < target) {
                    s = m + 1;
                } else {
                    e = m - 1;
                }
            }
        }
        return cp;
    }
};
