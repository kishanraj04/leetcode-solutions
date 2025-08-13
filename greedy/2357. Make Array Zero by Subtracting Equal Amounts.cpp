class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int c = 0;
        int i = 0;
       
        while(nums[nums.size()-1]>0){
            while(nums[i]==0) i++;

            int sub = nums[i];
            for(int t=i;t<nums.size();t++){
                nums[t]=nums[t]-sub;
            }

            c++;
        }

        return c;
    }
};