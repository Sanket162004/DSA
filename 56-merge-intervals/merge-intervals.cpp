class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        int n=interval.size();

        vector<vector<int>>result;

        if(interval.size()==0){
            return result;
        }
        
        sort(interval.begin(),interval.end(),[](vector<int>&a,vector<int>&b){
            return a[0]<b[0];
        });

        vector<int>curr=interval[0];

        for(int i=1;i<n;i++){
            if(curr[1]>=interval[i][0]){
                curr[1]=max(curr[1],interval[i][1]);
            }
            else{
                result.push_back(curr);
                curr=interval[i];
            }
        }
        result.push_back(curr);

        return result;
        
    }
};