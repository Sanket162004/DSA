class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int maxlen=0;
        

        while(j<n){
           if(nums[j]==1){
            j++;
           }
           else{
            maxlen=max(maxlen,j-i);
            j++;
            i=j;
           }
        }

         maxlen=max(maxlen,j-i);

         return maxlen;


    }
};