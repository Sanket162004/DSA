class Solution {
public:
    
    int solve(int idx,int n,vector<int>&dp){
        if(idx==n){
            return 1; 
        }

        if(idx>n){
            return 0;
        }

        if(dp[idx]!=-1){
            return dp[idx];
        }

        dp[idx]=solve(idx+1,n,dp)+solve(idx+2,n,dp);
        return dp[idx];
    }

    int climbStairs(int n) {
        int idx=0;

        vector<int>dp(n+1,-1);

        return solve(idx,n,dp);


    }
};