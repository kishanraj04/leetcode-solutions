class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=0;i--){
            int s=0;
            int e=i-1;
            while(s<e){
                if(nums[s]+nums[e]>nums[i]){
                    ans=ans+abs(e-s);
                    e--;
                }
                else{
                    s++;
                }
            }
        }
        return ans;
    }
};