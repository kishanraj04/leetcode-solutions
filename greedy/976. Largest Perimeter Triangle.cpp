class Solution {

int solv(vector<int> n , int a , int b , int c){
    if(a<0) return 0;
    else if(n[a]+n[b]>n[c]) return n[a]+n[b]+n[c];

    return solv(n,a-1,b-1,c-1); 
}

public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a = nums.size()-3, b = nums.size()-2, c = nums.size()-1;

        // while(a>=0){
        //     if(nums[a]+nums[b]>nums[c]){
        //         return nums[a]+nums[b]+nums[c];
        //     }else{
        //         a--;
        //         b--;
        //         c--;
        //     }
        // }
        // return 0;
        return solv(nums,a,b,c);
    }
};