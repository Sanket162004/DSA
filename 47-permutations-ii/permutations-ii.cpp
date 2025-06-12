class Solution {
public:
void solve(int n,vector<int>&temp,unordered_map<int,int>mp,vector<vector<int>>&ans){
    if(temp.size()==n){
        ans.push_back(temp);
        return;
    }

    for(auto &[num,count]:mp){
        if(count==0){
            continue;
        }

        temp.push_back(num);
        mp[num]--;


        solve(n,temp,mp,ans);

        temp.pop_back();
        mp[num]++;

        
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int>mp;

        for(auto &num:nums){
            mp[num]++;
        }

        vector<vector<int>>ans;
        vector<int>temp;

        int i=0;


        solve(n,temp,mp,ans);
        return ans;
    }
};