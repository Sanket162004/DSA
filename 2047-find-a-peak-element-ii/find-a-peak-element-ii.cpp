class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low=0;
        int high=mat[0].size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            int mxelmt=INT_MIN;
            int indx=-1;

            for(int i=0;i<mat.size();i++){
                if(mat[i][mid]>mxelmt){
                    mxelmt=mat[i][mid];
                    indx=i;
                }
            }
            int left=mid-1>=0?mat[indx][mid-1]:-1;
            int right=mid+1<(mat[0].size())?mat[indx][mid+1]:-1;

            if(mat[indx][mid]>left && mat[indx][mid]>right ){
                return {indx,mid};
            }else if(mat[indx][mid]<left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};