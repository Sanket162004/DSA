class Solution {
public:
    void combsum(vector<int>& candidates,int index,vector<vector<int>>&ans,int target,vector<int>temp){
            
            if(target==0){
                ans.push_back(temp);
                return ;
            }
            if(index==candidates.size()||target<0){
                return ;
            }
            
        //if we are not picking
        
        combsum(candidates,index+1,ans,target,temp);

        //now we are picking up

        temp.push_back(candidates[index]);
        
        combsum(candidates,index,ans,target-candidates[index],temp);






        //if i want to pick same element or not
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=candidates.size();


        combsum(candidates,0,ans,target,temp);
        return ans;


    }
};