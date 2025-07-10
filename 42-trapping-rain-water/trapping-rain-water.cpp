class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0; // Handle edge case of empty input

        // Step 1: Calculate left max for each bar
        vector<int> leftmax(n, 0);
        vector<int> rightmax(n, 0);

        leftmax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftmax[i] = max(leftmax[i - 1], height[i]);
        }

        // Step 2: Calculate right max for each bar
        rightmax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightmax[i] = max(rightmax[i + 1], height[i]);
        }

        // Step 3: Calculate the trapped water
        int water = 0;
        for (int i = 0; i < n; i++) {
            int minHeight = min(leftmax[i], rightmax[i]);
            if (minHeight > height[i]) {
                water += minHeight - height[i];
            }
        }

        return water;
    }
};
