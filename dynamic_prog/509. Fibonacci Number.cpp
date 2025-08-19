class Solution {

int cal(int n,vector<int> &dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=cal(n-1,dp)+cal(n-2,dp);
}

public:
    int fib(int n) {
        // if(n<=1) return n;

        // int ans = 0;
        // int st = 0;
        // int nd = 1;
        // for(int i=0;i<n-1;i++){
        //     ans=st+nd;
        //     st=nd;
        //     nd=ans;
        // }
        // return ans;
        vector<int> dp(n+1,-1);
        return cal(n,dp);
    }
};