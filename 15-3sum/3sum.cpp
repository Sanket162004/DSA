class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        

        int n=nums.size();

        vector<vector<int>>ans;

        sort(nums.begin(),nums.end());
        
        for(int k=0;k<n-2;k++){
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            int i=k+1;
            int j=n-1;

           
            int sum=0;

           

            while(i<j){
               sum=nums[k]+nums[i]+nums[j];

               if(sum==0){
                
                ans.push_back({nums[k],nums[i],nums[j]});

                while(i<j && nums[j]==nums[j-1]){
                    j--;
                }
                 while(i<j && nums[i]==nums[i+1]){
                    i++;
                }

                i++;
                j--;

                
               }

               if(sum>0){
                 
                
                j--;
               }

               if(sum<0){
               
                i++;
               }
            }
        }

        return ans;


    }
};