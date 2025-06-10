class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        else if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        // skip last house
        vector<int> skiplast;
        skiplast.push_back(nums[0]);
        skiplast.push_back(max(nums[0],nums[1]));
        for(int i=2;i<nums.size()-1;i++){
            skiplast.push_back(max(skiplast[i-2]+nums[i],skiplast[i-1]));
        }

        // skip first
        vector<int> skipfirst;
        skipfirst.push_back(nums[1]);
        skipfirst.push_back(max(nums[1],nums[2]));
        for(int j=3;j<nums.size();j++){
            skipfirst.push_back(max(skipfirst[j-3]+nums[j],skipfirst[j-2]));
        }
        cout<<skipfirst[skipfirst.size()-1];
        cout<<skiplast[skiplast.size()-1];
        return max(skipfirst[skipfirst.size()-1],skiplast[skiplast.size()-1]);
    }
};