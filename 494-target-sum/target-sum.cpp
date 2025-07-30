class Solution {
public:
    int solve(int i,int sum,vector<int>& nums, int target,int n){
        if(i==n){
            if(sum==target){
                return 1;
            }
            else{
                return 0;
            }
        }

        // 
        int plus=solve(i+1,sum+nums[i],nums,target,n);
        int minus=solve(i+1,sum-nums[i],nums,target,n);


        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int i=0;
        int n=nums.size();
        int sum=0;

        return solve(i,sum,nums,target,n);
    }
};