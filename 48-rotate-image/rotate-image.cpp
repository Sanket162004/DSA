class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        // pehle transpose kare ge

        for(int i=0;i<row;i++){
            for(int j=0;j<=i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // ab kar na hai rever se

        for(int i=0;i<row;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }


    }
};