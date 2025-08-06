class Solution {

void solv(vector<int> &nums,int idx,int &ope){
    if(idx>=nums.size()) return ;

    if(nums[idx]<=nums[idx-1]){
        int diff = abs(nums[idx]-nums[idx-1])+1;
        ope+=diff;
        nums[idx]=nums[idx]+diff;
    }
    solv(nums,idx+1,ope);
}

public:
    int minOperations(vector<int>& nums) {
        int ope =0;
        solv(nums,1,ope);
       
        return ope;
    }
};