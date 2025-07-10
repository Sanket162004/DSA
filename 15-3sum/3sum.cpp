class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>>ans;

        sort(nums.begin(),nums.end());

        for(int k=0;k<n-2;k++){
            if(k>0 && nums[k]==nums[k-1]){
                continue;
            }

            int i=k+1;
            int j=n-1;

            int sum=0;

            while(i<j){
                sum=nums[k]+nums[i]+nums[j];

                // tin condition sum ==0
                // sum >0
                //sum<0;

                if(sum==0){
                    ans.push_back({nums[k],nums[i],nums[j]});
                    // skip wali condition q ki aapne i j equal nahi rahe sake

                    while(i<j&& nums[j]==nums[j-1]){
                        j--;
                    }
                    while(i<j&&nums[i]==nums[i+1]){
                        i++;
                    }

                    // ans mil gaya further check karege ki answer mil ra kya 

                    i++;
                    j--;
                }

               else if(sum>0){
                    j--;
                }
                else{
                    i++;
                }
            }
        }

        return ans;

        
    }
};