class Solution {
public:
    void combsum(vector<int>& candidates, int index, vector<vector<int>>& ans, int target, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            // If current number exceeds target, no point in exploring further
            if (candidates[i] > target) break;

            temp.push_back(candidates[i]);
            combsum(candidates, i + 1, ans, target - candidates[i], temp); // i + 1 because we can use each element only once
            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        // Sort the array to handle duplicates and make early pruning possible
        sort(candidates.begin(), candidates.end());

        combsum(candidates, 0, ans, target, temp);
        return ans;
    }
};
