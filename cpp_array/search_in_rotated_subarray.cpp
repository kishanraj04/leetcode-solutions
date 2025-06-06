class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;

        while(start<=end && end>=0){
            if(nums[start]==target){
                return start;
            }
            if(nums[end]==target){
                return end;
            }
            if(nums[0]>target){
                end--;
            }
            if(nums[0]<target){
                start++;
            }
            
        }
        return -1;
    }
};