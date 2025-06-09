class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int maxlen=0;
        int no_of_zeros=0;

        while(j<n){
            if(nums[j]==0){
                no_of_zeros++;
            }
            if(no_of_zeros>k){
                if(nums[i]==0){
                    no_of_zeros--;
                    
                }
                i++;
            }

            maxlen=max(maxlen,j-i+1);

            j++;

            
        }
        return maxlen;
    }
};