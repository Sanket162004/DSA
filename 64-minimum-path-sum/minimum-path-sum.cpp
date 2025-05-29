class Solution {
public:
    int m,n;
    int t[201][201];
    int solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&t){
        if(i==m-1 && j==n-1){
            
            return grid[i][j];
        }
        if(i<0||i>=m||j<0||j>=n){
            return 0;
        }

        if(t[i][j]!=-1){
            return t[i][j];
        }

        //if(aapan last row mai hai)
        
        
        if(i==m-1){
            return t[i][j]=grid[i][j]+solve(grid,i,j+1,t);
        }
        else if(j==n-1){
            return t[i][j]=grid[i][j]+solve(grid,i+1,j,t);
        }

        else{
            // aapan left side right side dono ja sakte toh mini chosse karge 

            return t[i][j]=grid[i][j]+min(solve(grid,i+1,j,t),solve(grid,i,j+1,t));
        }





    }

    int minPathSum(vector<vector<int>>& grid) {
         m=grid.size();
         n=grid[0].size();

         vector<vector<int>>t(m+1,vector<int>(n+1,-1));

        return solve(grid,0,0,t);
    }
};