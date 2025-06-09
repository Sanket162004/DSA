class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();

        int start=0;
        int end=0;
        int cnt=1000000001;

        int sum=0;

        while(end<n){
            sum=sum+nums[end];
            while(sum>=target){
                cnt=min(cnt,end-start+1);
                sum=sum-nums[start];
                start++;
            }
            end++;
            
        }
        if(cnt==1000000001){
            return 0;
        }
        return cnt;
    }
};