class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

         if(binary_search(nums.begin(),nums.end(),target)){
            return true;
         }
         else{
            return false;
         }
    }
};