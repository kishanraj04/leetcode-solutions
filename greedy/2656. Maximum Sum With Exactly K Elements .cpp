class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int res = 0;
        int move = 0;

        int maxe = INT_MIN;
        for(int val:nums){
            maxe = max(val,maxe);
        }

        for(int i=0;i<k;i++){
            res+=(maxe+move);
            move++;
        }
        return res;
    }
};