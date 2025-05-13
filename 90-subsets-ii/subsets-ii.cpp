class Solution {
public:
    void subsequence(vector<int>& nums,int index,int n,vector<vector<int>>&ans,vector<int>temp){
        ans.push_back(temp);

        
        //yes
        for (int i = index; i < nums.size(); i++) {
            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1])
                continue;

            temp.push_back(nums[i]);
            subsequence(nums, i + 1, n,ans, temp);
            temp.pop_back(); // backtrack
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;

        sort(nums.begin(),nums.end());

        subsequence(nums,0,n,ans,temp);
        return ans;
    }
};