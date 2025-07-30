class Solution {
public:
int dp[300][5001];
    int solve(vector<int>& coins,int amount ,int i){
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

        int take=solve(coins,amount-coins[i],i);

        int dont_take=solve(coins,amount,i+1);

        return dp[i][amount]=take+dont_take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int i=0;
        memset(dp,-1,sizeof(dp));
      
        return solve(coins,amount,0);

    }
};