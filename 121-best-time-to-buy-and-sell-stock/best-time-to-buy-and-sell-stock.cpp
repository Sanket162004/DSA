class Solution {
public:
    int maxProfit(vector<int>& nums) {
        
        int n=nums.size();
        int maxprofit=0;
        int right_max=nums[n-1];

        for(int i=n-2;i>=0;i--){

            if(nums[i]>right_max){
                right_max=nums[i];
            }

            maxprofit=max(maxprofit,right_max-nums[i]);
        }

        return maxprofit;
    }
};