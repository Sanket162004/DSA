class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1;

        int r=*max_element(nums.begin(),nums.end());


        while(l<r){
            int mid=l+(r-l)/2;

            int count=0;

            for(int i=0;i<n;i++){

                int num=nums[i];

                count=count+num/mid;

                if(num%mid!=0){
                    count++;
                }
            }

            if(count>threshold){
                l=mid+1;
            }
            else{
                r=mid;
            }


        }

        return r;
    }
};