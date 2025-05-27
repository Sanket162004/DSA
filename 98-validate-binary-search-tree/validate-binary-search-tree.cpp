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
void inorder(TreeNode*root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);

    }
    bool isValidBST(TreeNode* root) {
        
        vector<int>ans;

        inorder(root,ans);
        int n=ans.size();
        int x=0;
        if(n==2){
           if(ans[x]>=ans[x+1]){
            return false;
           }
        }
        else{
            for(int i=1;i<n-1;i++){
            if(ans[i]==ans[i-1]||ans[i]==ans[i+1]){
                return false;
            }
            if(ans[i]<ans[i-1]||ans[i]>ans[i+1]){
                return false;
            }
          }
        }
        

        return true;

    }
};