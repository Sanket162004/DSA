class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){

            int num=nums[i];


            if(mp.find(num)!=mp.end()){
                mp[num]++;
            }

            else{
                mp[num]=1;
            }
        }


        for(auto it=mp.begin();it!=mp.end();it++){

            if(it->second>n/2){
                return it->first;
            }
        }

        return -1;
    }
};