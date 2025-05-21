/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxsum;

    int solve(TreeNode* root) {
        if (root == NULL) return 0;

        // Only take positive contributions from left and right
        int l = max(0, solve(root->left));
        int r = max(0, solve(root->right));

        // Max path through current node (including both left and right)
        int pathThroughRoot = l + r + root->val;

        // Update global maxsum
        maxsum = max(maxsum, pathThroughRoot);

        // Return max one-side path to parent
        return max(l, r) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;
        solve(root);
        return maxsum;
    }
};
