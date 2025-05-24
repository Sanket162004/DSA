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
    int find(vector<int>& inorder,int target,int start,int end){
        for(int i=start;i<=end;i++){
            if(inorder[i]==target){
                return i;
            }
        }
        return 0;
    };
    TreeNode*tree(vector<int>& preorder, vector<int>& inorder,int start,int end,int index){
        if(start>end){
            return NULL;
        }
        TreeNode*root=new TreeNode(preorder[index]);

        int pos=find(inorder,preorder[index],start,end);

        root->left=tree(preorder,inorder,start,pos-1,index+1);
        root->right=tree(preorder,inorder,pos+1,end,index+(pos-start+1));

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int start=0;
        int end=n-1;

        int index=0;

        return tree(preorder,inorder,start,end,index);
    }
};