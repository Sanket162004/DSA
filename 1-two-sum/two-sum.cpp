class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        // using unordered map;

        unordered_map<int,int>pairidx;


        for(int i=0;i<n;i++){
            int num=nums[i];

            int moreneeded=target-nums[i];

            if(pairidx.find(moreneeded)!=pairidx.end()){
                return {pairidx[moreneeded],i};
            }
            pairidx[num]=i;
        }
        return {-1,-1};
    }
};