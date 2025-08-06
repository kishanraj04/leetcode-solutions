class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        
        // sort the nums
        sort(nums.begin(),nums.end());

        // cal the total sum
        int sum = 0;
        for(int val:nums) sum+=val;

        int ts = 0;
        vector<int> res;

        for(int i=nums.size()-1;i>=0;i--){
            if(ts<=sum) res.push_back(nums[i]);
            sum-=nums[i];
            ts+=nums[i];
            if(ts>sum) break;
        }

        return res;
    }
};