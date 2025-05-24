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
    int countNodes(TreeNode* root) {

        if(root==NULL){
            return 0;
        }

        int n=0;
        queue<TreeNode*>q;
        q.push(root);

         n=n+1;

        while(q.empty()==0){
            int x=q.size();

            while(x--){
                TreeNode*curr=q.front();
                q.pop();
               

                if(curr->left){
                    q.push(curr->left);
                    n=n+1;
                }
                if(curr->right){
                    q.push(curr->right);
                    n=n+1;
                }
            }
        }

        return n;




    }
};