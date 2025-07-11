class Solution {
public:

    void solve(int index,vector<int>& nums,vector<vector<int>>&ans,vector<int>&temp,int n){
        if(index>=n){
            ans.push_back(temp);
            return ;
        }


        // aagar lena hai 

        temp.push_back(nums[index]);
        solve(index+1,nums,ans,temp,n);
        temp.pop_back();

        int i=index+1;

        while(i<n && nums[i]==nums[i-1]){
            i++;
        }

        solve(i,nums,ans,temp,n);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        vector<vector<int>>ans;
        vector<int>temp;
        int index=0;

        solve(index,nums,ans,temp,n);

        return ans;
    }
};