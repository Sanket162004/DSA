class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;

        vector<int>ans;

        for(int i=0;i<nums.size();i++){
            int num=nums[i];

            if(mp.find(num)!=mp.end()){
                mp[num]++;
            }

            if(mp.find(num)==mp.end()){
                mp[num]=1;
            }
        }

        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second >nums.size()/3){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};