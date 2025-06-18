class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row=matrix.size();
        int col=matrix[0].size();

        for(int j=0;j<col;j++){
            int l=0;
            int r=row-1;

            while(l<=r){
                int mid=l+(r-l)/2;
                
                if(matrix[mid][j]==target){
                    return true;
                }

                if(matrix[mid][j]>target){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }

            } 
        }
        return false;
        
    }
};