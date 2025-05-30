class Solution {
public:
    int solve(vector<int>& arr, int i, int k, int n, vector<int>& dp) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        int result = 0;
        int curr_max = -1;

        for (int j = i; j < n && j - i + 1 <= k; j++) {
            curr_max = max(curr_max, arr[j]);
            int len = j - i + 1;
            result = max(result, (len * curr_max) + solve(arr, j + 1, k, n, dp));
        }

        return dp[i] = result;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, 0, k, n, dp);
    }
};
