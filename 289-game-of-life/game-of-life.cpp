class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        return(i>=0 && j>=0 && i<m && j<n);
    }
    int getLiveNeighbours(vector<vector<int>>& board,int i,int j){
        int m = board.size(),n=board[0].size();
        int live = 0;
        vector<vector<int>>ne = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int k=0;k<ne.size();k++){
            if(isValid(i+ne[k][0],j+ne[k][1],m,n) && (board[i+ne[k][0]][j+ne[k][1]]>0)) live ++;
        }
        return live;
    }
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int liveNeighbours = getLiveNeighbours(board,i,j);
                if((liveNeighbours<2 || liveNeighbours>3) && board[i][j]==1){ 
                   board[i][j] = 2;
                }
                else if(board[i][j]==0 && liveNeighbours==3) {board[i][j] = -2;}

            }
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==2) board[i][j] = 0;
                else if(board[i][j]==-2) board[i][j] = 1;
            }
        }

    }
};