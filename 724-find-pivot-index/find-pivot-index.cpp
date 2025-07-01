class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // pehle prifix sum nikal lete hai

        int sum=0;

        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }

        

        int leftsidesum=0;
        int rightsidesum=sum-nums[0];


        for(int i=0;i<nums.size();i++){

             rightsidesum=sum-nums[i]-leftsidesum;

            if(leftsidesum==rightsidesum){
                return i;
            }

            
                leftsidesum=leftsidesum+nums[i];
               
          
        }

        

        return -1;
    }
};