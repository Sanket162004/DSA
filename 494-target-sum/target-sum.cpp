class Solution {
public:
    int dp[21][2001];
    int solve(vector<int>& nums, int target,int i,int x){
        if(i==nums.size() && target!=x){
            return 0;
        }
        if(target==x && i==nums.size()){
            return 1;
        }
        if (dp[i][x + 1000] != -1) return dp[i][x + 1000];
       
        int postive=solve(nums,target,i+1,x+nums[i]);

        int negative=solve(nums,target,i+1,x-nums[i]);

        return dp[i][x + 1000]=postive+negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        memset(dp,-1,sizeof(dp));
        return solve(nums,target,0,0);

       

    }
};