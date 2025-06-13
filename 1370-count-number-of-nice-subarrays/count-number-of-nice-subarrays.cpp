class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // Convert odd numbers to 1, even numbers to 0
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] % 2;
        }

        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // One way to get sum 0 at start

        int sum = 0, count = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            // If sum - k has occurred before, add the frequency to count
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }

            // Record the current prefix sum
            prefixSumCount[sum]++;
        }

        return count;
    }
};
