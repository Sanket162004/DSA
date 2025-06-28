class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        if(row==1){
            if(matrix[0][0]==target){
                return true;
            }
        }

        for(int i=0;i<row;i++){

            int l=0;
            int r=col-1;

            while(l<=r){
                int mid=l+(r-l)/2;

                if(matrix[i][mid]==target){
                    return true;

                }
                if(matrix[i][mid]<target){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }

        return false;
    }
};