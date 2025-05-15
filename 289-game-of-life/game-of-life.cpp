class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int tmp = howManyLivePartnersCellHas(i,j,board);
                if(board[i][j]==0){
                    if(tmp==3) board[i][j]=3;
                }
                else{
                    if(tmp<2 || tmp>3) board[i][j]=2;
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==2) board[i][j]=0;
                else if(board[i][j]==3) board[i][j]=1;
            }
        }
    }
    int howManyLivePartnersCellHas(int m,int n,vector<vector<int>>& board){
        int liveneighs=0;
        if(m-1>=0 && n-1>=0){
            if(board[m-1][n-1]==2 || board[m-1][n-1]==1) liveneighs++;
        }
        if(m-1>=0){
            if(board[m-1][n]==2 || board[m-1][n]==1) liveneighs++;
        }
        if(m-1>=0 && n+1<board[0].size()){
            if(board[m-1][n+1]==2 || board[m-1][n+1]==1) liveneighs++;
        }
        if(n-1>=0){
            if(board[m][n-1]==2 || board[m][n-1]==1) liveneighs++;
        }
        if(m+1<board.size()){
            if(board[m+1][n]==2 || board[m+1][n]==1) liveneighs++;
        }
        if(n+1<board[0].size()){
            if(board[m][n+1]==2 || board[m][n+1]==1) liveneighs++;
        }
        if(m+1<board.size() && n-1>=0){
            if(board[m+1][n-1]==2 || board[m+1][n-1]==1) liveneighs++;
        }
        if(m+1<board.size() && n+1<board[0].size()){
            if(board[m+1][n+1]==2 || board[m+1][n+1]==1) liveneighs++;
        }
        return liveneighs;
    }
};