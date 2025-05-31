class Solution {
public:
    int solve(vector<int>& coins,int amount ,int i,vector<vector<int>>&dp){
        if(i==coins.size()){
            return 0;
        }

        if(amount<0){
            return 0;
        }
        if(amount ==0){
            return 1;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }

        int take=solve(coins,amount-coins[i],i,dp);

        int dont_take=solve(coins,amount,i+1,dp);

        return dp[i][amount]=take+dont_take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int i=0;
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(coins,amount,0,dp);

    }
};