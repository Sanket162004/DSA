class Solution {
public:
    void subsequence(vector<int>& nums,int index,int n,vector<vector<int>>&ans,vector<int>temp){
        if(index==n){
            ans.push_back(temp);
            return ;
        }

        //no
        subsequence(nums,index+1,n,ans,temp);
        //yes
        temp.push_back(nums[index]);
        subsequence(nums,index+1,n,ans,temp);

    }
    
    vector<vector<int>> subsets(vector<int>& nums) {

        int n=nums.size();

        vector<vector<int>>ans;

        vector<int>temp;

        subsequence(nums,0,n,ans,temp);
        return ans;


        
    }
};