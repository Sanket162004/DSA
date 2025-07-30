class Solution {
public:
    int longestCommonSubsequence(string x, string y) {
        int m=x.size();
        int n=y.size();


        // 2d vector banaye ge

        vector<vector<int>>t(m+1,vector<int>(n+1));

        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0){
                    t[i][j]=0;
                }
            }
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(x[i-1]==y[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i][j-1],t[i-1][j]);
                }
            }
        }

        return t[m][n];
    }
};