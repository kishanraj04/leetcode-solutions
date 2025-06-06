class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int ptr1=0;
        int ptr2=nums.size()-1;
        while(ptr1<=ptr2){
            if(nums[ptr1]==target || nums[ptr2]==target){
                return true;
            }else{
                if(nums[ptr1]>target){
                    ptr2--;
                }else{
                    ptr1++;
                }
            }
        }
        return false;
    }
};