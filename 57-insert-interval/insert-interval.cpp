class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;

        // 1. Add all intervals ending before newInterval starts
        while (i < n && newInterval[0] > intervals[i][1]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // 2. Merge all overlapping intervals
        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        // Add the merged interval
        ans.push_back(newInterval);

        // 3. Add all remaining intervals
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};
