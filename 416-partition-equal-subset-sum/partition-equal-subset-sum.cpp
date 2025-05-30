class Solution {
public:
    bool solve(vector<int>& nums,int i,int x,int n,vector<vector<int>>&dp){
        if(x==0){
            return true;
        }
        if(i>=n){
            return false;
        }
        if(dp[i][x]!=-1){
            return dp[i][x];
        }

        bool take =false;

        if(x>=nums[i]){
            take=solve(nums,i+1,x-nums[i],n,dp);
        }

        bool not_take=solve(nums,i+1,x,n,dp);

        return dp[i][x]=take||not_take;


    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();

        int s=accumulate(nums.begin(),nums.end(),0);

        if(s%2!=0){
            return false;

        }
        int x=s/2;
         vector<vector<int>>dp(n,vector<int>(x+1,-1));
        int i=0;
         return solve(nums,i,x,n,dp);
         

        
    }
};