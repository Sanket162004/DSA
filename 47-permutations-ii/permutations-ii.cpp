class Solution {
public:
    void solve(unordered_map<int,int>&mp,int n,vector<int>&temp,vector<vector<int>>&ans){
        if(temp.size()==n){
            ans.push_back(temp);
            return ;
        }

        for(auto &[num,count]:mp){
            if(count==0){
                continue;
            }

            temp.push_back(num);
            mp[num]--;

            solve(mp,n,temp,ans);

            temp.pop_back();
            mp[num]++;                                                      

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>>ans;

        unordered_map<int,int>mp;

        for(auto &num:nums){
            mp[num]++;
        }
        vector<int>temp;

        solve(mp,n,temp,ans);
        return ans;
    }
};