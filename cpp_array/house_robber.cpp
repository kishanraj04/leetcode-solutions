class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> res;
        if(nums.size()==1){
            return nums[0];
        }else{
            res.push_back(nums[0]);
            res.push_back(max(nums[0],nums[1]));

            for(int i=2;i<nums.size();i++){
                res.push_back(max(res[i-2]+nums[i],res[i-1]));
            }

        }

        return res[res.size()-1];
    }
};