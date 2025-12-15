class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();

        int left=0;
        int right=1;

        while(right<n){
            if(nums[left]==nums[right]){
                right++;
            }
            else{
                left++;
                swap(nums[left],nums[right]);
                right++;
            }
        }

        return left+1;


    }
};