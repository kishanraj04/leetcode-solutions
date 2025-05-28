class Solution {
public:
    void sortColors(vector<int>& nums) {
        int m=0;
        int l=0;
        int r=nums.size()-1;

        while(m<=r){
             if(nums[m]==2){
                int tmp=nums[m];
                nums[m]=nums[r];
                nums[r]=tmp;
                r--;
            }
            else if(nums[m]==0){
                int tmp=nums[m];
                nums[m]=nums[l];
                nums[l]=tmp;
                l++;
                m++;            
            }
            else{
                m++;
            }
        }
    }
};