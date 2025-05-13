class Solution {
public:

    unordered_set<int>st;
    void slove(vector<int>& nums,vector<int>& temp,vector<vector<int>>&ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i])==st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);

                slove(nums,temp,ans); 

                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<int>temp;
       vector<vector<int>>ans;

       slove(nums,temp,ans); 
       return ans;
    }
};