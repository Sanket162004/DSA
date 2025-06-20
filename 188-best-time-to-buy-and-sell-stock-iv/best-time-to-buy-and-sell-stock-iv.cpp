class Solution {
public:
int dp[1001][2][100];
    int n,trans;
    vector<int> nums;
    int rec(int i, int j, int k) {
        if (k >= trans|| i >= n)
            return 0;
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        int ans = 0;
        ans = max(ans, rec(i + 1, j, k));
        if (j == 0)
            ans = max(ans, rec(i + 1, 1, k) - nums[i]);
        if (j == 1)
            ans = max(ans, rec(i + 1, 0, k + 1) + nums[i]);
        dp[i][j][k] = ans;
        return ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        nums = prices;
        trans=k;
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, 0);
    }
};