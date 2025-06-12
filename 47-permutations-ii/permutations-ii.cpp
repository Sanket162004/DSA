class Solution {
public:
void solve(int n,vector<int>&temp,unordered_map<int,int>mp,vector<vector<int>>&ans){
    if(temp.size()==n){
        ans.push_back(temp);
        return;
    }
    for (auto  it = mp.begin(); it != mp.end(); ++it) {
    int num = it->first;
    int &count = it->second;

    // same logic...
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

                    

      for (int i = 0; i < nums.size(); i++) {
           int num = nums[i];

           if (mp.find(num) != mp.end()) {
              mp[num] = mp[num] + 1;
           } else {
           mp[num] = 1;
      }
    }


        vector<vector<int>>ans;
        vector<int>temp;

        int i=0;


        solve(n,temp,mp,ans);
        return ans;
    }
};



