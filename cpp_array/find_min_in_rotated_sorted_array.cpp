class Solution {
public:
    int findMin(vector<int>& nums) {
        int min=INT_MAX;
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(nums[mid]<min) min=nums[mid];

            if(nums[mid]>=nums[s] && nums[mid]>=nums[e]){
                s=mid+1;
            }else {
                e=mid-1;
            }
            
        }

        return min;
    }
};