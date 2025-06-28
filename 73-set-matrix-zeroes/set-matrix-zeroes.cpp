class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        // fhele zeron find karega matrix mai

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    //ab jo zero aaya hai uske verticall pure o kar ne hai

                    for(int k=0;k<row;k++){
                        if(matrix[k][j]!=0){
                            matrix[k][j]=999999;
                        }
                    }


                    // same for horizontal
                    for(int k=0;k<col;k++){
                        if(matrix[i][k]!=0){
                            matrix[i][k]=999999;
                        }
                    }

                }
            }
        }


        // jaha 999999 hai usko 0 kar duga

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==999999){
                    matrix[i][j]=0;
                }
            }
        }

            
    }
};