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
    int total_sum = 0;
public:
    int sumNumbers(TreeNode* root) {
        // Iterative

        // make a pair for <node, curr_value> 
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, 0});

        int total_sum = 0;
        while (!stk.empty()) {
            auto [curr_node, curr_val] = stk.top(); 
            stk.pop();

            int combined_val = curr_val * 10 + curr_node->val;

            if (!curr_node->left && !curr_node->right) {
                total_sum += combined_val;
            }

            if (curr_node->left) {
                stk.push({curr_node->left, combined_val});
            }
            if (curr_node->right) {
                stk.push({curr_node->right, combined_val});
            }
        }

        return total_sum;
    }
};