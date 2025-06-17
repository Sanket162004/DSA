class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int maxi = 0;

        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }

        int l = 1;
        int r = maxi;

        while (l < r) {
            int mid = l + (r - l) / 2;

            int count = 0;

            for (int i = 0; i < nums.size(); i++) {
                count += (nums[i] + mid - 1) / mid;  // ceil(nums[i] / mid)
            }

            if (count > h) {
                l = mid + 1;  // speed too slow, increase
            } else {
                r = mid;      // maybe we can slow down more
            }
        }

        return l;  // minimum speed
    }
};
