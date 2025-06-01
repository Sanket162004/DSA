class Solution {
public:
int t[5001][2];
    int solve(vector<int>& prices,int i,int n,bool buy){
        if(i>=n){
            return 0;
        }

        int profit=0;
        if(t[i][buy]!=-1){
            return t[i][buy];
        }

        if(buy){
            int take =solve(prices,i+1,n,false)-prices[i];

            int dont_take=solve(prices,i+1,n,true);

            profit=max({profit,take,dont_take});
        }

        else{
            int sell=prices[i]+solve(prices,i+2,n,true);

            int dont_sell=solve(prices,i+1,n,false);

            profit=max({profit,sell,dont_sell});
        }

        return t[i][buy]=profit;
        
        
        

       
        

    }
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int n=prices.size();
        memset(t,-1,sizeof(t));
        bool buy=true;
        return solve(prices,0,n,buy);
    }
};