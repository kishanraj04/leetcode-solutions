class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs=0;
        int maxsum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            cs=cs+nums[i];
            maxsum=max(cs,maxsum);
            if(cs<0) cs=0;
        }

        return maxsum;
    }
};