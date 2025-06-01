class Solution {
public:
    int t[2501][2501];
    int solve(vector<int>& nums,int i,int n,int pre){
        if(i==n){
            return 0;
        }
         
         if(t[i][pre+1]!=-1){
            return t[i][pre+1];
         }
        int take=0;
        if(pre==-1||nums[pre]<nums[i])
         take=1+solve(nums,i+1,n,i);

        int dont_take=0+solve(nums,i+1,n,pre);

        return t[i][pre+1]=max(take,dont_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        int i=0;
        int pre=-1;
        memset(t,-1,sizeof(t));
        return solve(nums,i,n,pre);
    }
};