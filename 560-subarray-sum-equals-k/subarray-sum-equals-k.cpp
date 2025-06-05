class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>prefixsum(n);

        prefixsum[0]=nums[0];

        for(int i=1;i<n;i++){
            prefixsum[i]=prefixsum[i-1]+nums[i];
        }

        int cnt=0;

        for(int j=0;j<n;j++){
            if(prefixsum[j]==k){
                cnt++;
            }
            int i=0;
            for ( i = 0; i < j; i++) {
                if (prefixsum[j] - prefixsum[i] == k) {
                    cnt++;
                }
            }
            


        }
        return cnt;
    }
};