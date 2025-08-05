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
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int> ans;

        while (root) {
            // Case 1: If left subtree doesn't exist
            if (root->left == NULL) {
                ans.push_back(root->val);  // Visit the node
                root = root->right;        // Move to right subtree
            }
            else {
                // Find the rightmost node of the left subtree
                TreeNode* curr = root->left;
                while (curr->right && curr->right != root) {
                    curr = curr->right;
                }

                // Case 2: First time visiting this node, build the thread
                if (curr->right == NULL) {
                    ans.push_back(root->val);
                    curr->right = root;     // Create thread (temporary link)
                    root = root->left;      // Move to left subtree
                }
                // Case 3: Already visited left subtree, remove the thread
                else {
                    curr->right = NULL;     // Remove the thread
                     // Visit the node
                    root = root->right;        // Move to right subtree
                }
            }
        }

        return ans;
    }
};