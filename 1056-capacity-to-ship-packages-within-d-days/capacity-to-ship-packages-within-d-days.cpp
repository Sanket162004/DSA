class Solution {
public:
    int shipWithinDays(vector<int>& nums, int days) {
        int n=nums.size();

        int l = *max_element(nums.begin(), nums.end());

        //sab ka sum kya bolta

        int sum=0;
        int mini_days=0;

        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }

        int r=sum;

        while(l<=r){
            int mid=l+(r-l)/2;

            int curr_sum=0;
            int counted_days=0;

            for(int i=0;i<n;i++){

                

                if(curr_sum+nums[i]>mid){
                   counted_days=counted_days+1;
                   curr_sum=0;
                }
                curr_sum=curr_sum+nums[i];
                
            }

            counted_days++;

            if(counted_days>days){
                l=mid+1;
            }

            else{
                mini_days=mid;
                r=mid-1;
            }
           

            
        }

        return mini_days;
    }
};