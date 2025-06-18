class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int n=nums.size();

        int l=1;
        int r=*max_element(nums.begin(),nums.end());

        while(l<r){
            int mid=l+(r-l)/2;

            long long count=0;

            for(int i=0;i<n;i++){
                int num=nums[i];
                count=count+num/mid;

                if(num%mid != 0){
                    count ++;
                }

                

            }

            if(count>h){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }

        return  r;
    }
};