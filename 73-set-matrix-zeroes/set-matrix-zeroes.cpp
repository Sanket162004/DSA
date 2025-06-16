class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    // pehle col ko -1 se assign kar dete hai 
                    for(int k=0;k<row;k++){
                        if(matrix[k][j]!=0 && matrix[k][j]!=-999999){
                            matrix[k][j]=-999999;
                        }
                    }
                    // ab row ke pure element zero kar dete 
                    for(int k=0;k<col;k++){
                        if(matrix[i][k]!=0 && matrix[i][k]!=-9999999){
                            matrix[i][k]=-999999;
                        }
                    }
                }
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==-999999){
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};