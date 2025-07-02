class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) sum += num;

        // Check if (sum + target) is even and non-negative
        if ((sum + target) % 2 != 0 || (sum + target) < 0) return 0;

        int subsetSum = (sum + target) / 2;
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(subsetSum + 1, 0));

        // Initialization: ways to get sum 0 is 1 (empty subset)
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= subsetSum; j++) {
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][subsetSum];
    }
};