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
    // Returns height if balanced, -1 if unbalanced
    int checkheight(TreeNode* root) {
        if (root == NULL) return 0;

        int leftheight = checkheight(root->left);
        if (leftheight == -1) return -1;  // Left subtree unbalanced

        int rightheight = checkheight(root->right);
        if (rightheight == -1) return -1; // Right subtree unbalanced

        if (abs(leftheight - rightheight) > 1) return -1; // Current node unbalanced

        return max(leftheight, rightheight) + 1; // Return height
    }

    bool isBalanced(TreeNode* root) {
        return checkheight(root) != -1;
    }
};
