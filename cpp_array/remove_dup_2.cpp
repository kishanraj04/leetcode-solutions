class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
          int freq = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (freq < 2 || nums[i] != nums[freq - 2]) {
                nums[freq++] = nums[i];
            }
        }
        return freq;
    }
};