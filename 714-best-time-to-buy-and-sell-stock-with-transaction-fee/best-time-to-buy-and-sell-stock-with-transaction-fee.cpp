class Solution {
public:
    int t[50001][2];

    int solve(vector<int>& prices, int i, int n, bool buy, int fee) {
        if (i >= n) return 0;

        if (t[i][buy] != -1) return t[i][buy];

        int profit = 0;

        if (buy) {
            int take = solve(prices, i + 1, n, false, fee) - prices[i];
            int dont_take = solve(prices, i + 1, n, true, fee);
            profit = max(take, dont_take);
        } else {
            int sell = prices[i] - fee + solve(prices, i + 1, n, true, fee);
            int dont_sell = solve(prices, i + 1, n, false, fee);
            profit = max(sell, dont_sell);
        }

        return t[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        memset(t, -1, sizeof(t));
        return solve(prices, 0, n, true, fee);
    }
};
