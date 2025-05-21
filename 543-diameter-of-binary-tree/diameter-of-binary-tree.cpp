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
    int diameter(TreeNode*root,int &maxdia){
        if(root==NULL){
            return 0;
        }

        int LH=diameter(root->left,maxdia);

        int RH=diameter(root->right,maxdia);

        maxdia=max(maxdia,LH+RH);

        return 1+max(LH,RH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxdia=INT_MIN;
       diameter(root,maxdia); 
       return maxdia;
    }
};