class Solution {
public:
    void solve(vector<int>& nums,int i,int n,vector<vector<int>>&ans,vector<int>temp){
        if(i>=n){
            ans.push_back(temp);
            return;
        }
        // not take 
        solve(nums,i+1,n,ans,temp);
        // take

        temp.push_back(nums[i]);

        solve(nums,i+1,n,ans,temp);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        int i=0;
        solve(nums,i,n,ans,temp);
        return ans;
    }
};