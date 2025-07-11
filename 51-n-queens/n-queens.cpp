class Solution {
private:
    //  place kar ni ki  condition 2
    bool CanPlace(int row,int col,vector<string>board,int n){
        int tr=row,tc=col;
        while(row>=0 && col>=0) if(board[row--][col--]=='Q') return false;

        row=tr,col=tc;
        while(col>=0) if(board[row][col--]=='Q') return false;

        col=tc;
        while(row<n && col>=0) if(board[row++][col--]=='Q') return false;
        return true;
    }

    void solve(int col,vector<vector<string>>& res,vector<string>& board,int n){
        if(col==n){
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(CanPlace(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,res,board,n);
                board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,res,board,n);
        return res;
    }
};