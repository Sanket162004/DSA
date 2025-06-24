class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int jump=nums[0];
        while(i!=n-1){
            if (jump==0 && nums[i]==0){
                return false;
            }
            else if (jump>0){
                i++;
                jump--;
                if (jump<nums[i]){
                    jump=nums[i];
                }
            }
        }
        return true;
    }
};