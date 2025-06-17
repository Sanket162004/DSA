class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        int element=0;
        for(int i=0;i<n;i++){

            element=element^nums[i];

        }
        return element;
    }
};