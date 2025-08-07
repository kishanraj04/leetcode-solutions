class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mg = 0;
        for(int i=0;i<nums.size();i++){
            if(mg>=nums.size()-1) return true;
            else if(i>mg) return false;
            else{
                mg = max(mg,i+nums[i]);
            }
            if(mg==0) return false;
        }
        return false;
    }
};