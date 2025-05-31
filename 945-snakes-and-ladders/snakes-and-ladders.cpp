class Solution {
public:
    pair<int,int> getCoord(int val, int n){
        int RT = (val - 1)/n;
        int RB = n - 1 - RT;

        int col = (val - 1)%n;
        if((n%2==1 && RB%2==1) || (n%2==0 && RB%2== 0) ){
            col = n - 1 - col;
        }
        return {RB, col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int steps = 0;

        queue<int>q;
        vector<vector<bool>> visited(n, vector<bool>(n,0));
        q.push(1);
        visited[n-1][0] = 1;

        while(!q.empty()){
            int N = q.size();
            while(N--){
                int x = q.front();
                q.pop();

                if(x == n*n) return steps;

                for(int k = 1; k<=6; k++){
                    int val = x + k;
                    if(val > n*n) break;
                    pair<int,int> coor = getCoord(val, n);
                    int row = coor.first;
                    int col = coor.second;

                    if(visited[row][col]) continue;
                    visited[row][col] = 1;

                    if(board[row][col]!=-1){
                        q.push(board[row][col]);
                    }else{
                        q.push(val);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};