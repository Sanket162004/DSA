class Solution {
public:
   int solve(int i,vector<int>& nums,vector<int>&dp){
        
    if(i==0){
        return nums[i];
    }

    if(i<0){
        return 0;
    }

    if(dp[i]!=-1){
        return dp[i];
    }
    
    int pick=nums[i]+solve(i-2,nums,dp);

    int dontpick=0+solve(i-1,nums,dp);

    return dp[i]=max(pick,dontpick);


   }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int i=n-1;
        vector<int>dp(n+1,-1);
        return solve(i,nums,dp);
    }
};