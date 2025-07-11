class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int>& temp, set<vector<int>>& st) {
        if (i == nums.size()) {
            vector<int> subset = temp;
            sort(subset.begin(), subset.end()); // sort to handle unordered duplicates
            st.insert(subset);
            return;
        }

        // Include nums[i]
        temp.push_back(nums[i]);
        solve(i + 1, nums, temp, st);

        // Exclude nums[i]
        temp.pop_back();
        solve(i + 1, nums, temp, st);
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
