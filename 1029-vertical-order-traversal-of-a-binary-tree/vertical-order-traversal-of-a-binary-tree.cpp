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

class Custom {
public:
    int val;
    int row;
    int col;
    
    Custom(int v, int r, int c) {
        val = v;
        row = r;
        col = c;
    }
};

// Custom comparator for sorting
bool cmp(const Custom &a, const Custom &b) {
    if (a.col != b.col) return a.col < b.col;
    if (a.row != b.row) return a.row < b.row;
    return a.val < b.val;
}

class Solution {
public:
    void dfs(TreeNode* root, int row, int col, vector<Custom>& nodes) {
        if (!root) return;
        
        nodes.emplace_back(root->val, row, col);
        
        dfs(root->left, row + 1, col - 1, nodes);
        dfs(root->right, row + 1, col + 1, nodes);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<Custom> nodes;
        dfs(root, 0, 0, nodes);
        
        sort(nodes.begin(), nodes.end(), cmp);
        
        vector<vector<int>> result;
        int last_col = INT_MIN;
        
        for (const auto& node : nodes) {
            if (node.col != last_col) {
                result.push_back({});
                last_col = node.col;
            }
            result.back().push_back(node.val);
        }
        
        return result;
    }
};