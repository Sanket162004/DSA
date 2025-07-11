class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int>& temp, set<vector<int>>& st) {

        if(i>=nums.size()){
            vector<int>subset=temp;
            // sort kar lege q ki duplicate nahi lena 
            sort(subset.begin(),subset.end());
            st.insert(subset);
            return;
            

        }

        temp.push_back(nums[i]);

        solve(i+1,nums,temp,st);

        temp.pop_back();

        solve(i+1,nums,temp,st);
        
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> temp;
        solve(0, nums, temp, st);

        // Convert set to vector
        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }
};
