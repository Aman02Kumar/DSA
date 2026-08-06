class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];

        queue <pair<pair<int,int>,int >> q;
        int t = 0 ;
        int fresh = 0 ;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){

                if(grid[i][j]==2 ){
                    q.push({{i,j},t});
                    vis[i][j]=1;
                }
                else {
                    vis[i][j]=0;
                    if(grid[i][j]==1)
                        fresh++;
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int tm = q.front().second;

            t = max(t,tm);

            int dr[] = {1,0,-1,0};
            int dc[] = {0,1,0,-1};
            q.pop();

            for(int i = 0 ; i < 4;i++){

                int nr = r + dr[i];
                int nc = c + dc[i];

                if( nc >= 0 && nr>=0 && nc < m && nr < n && vis[nr][nc] == 0 && grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},t+1});
                    fresh--;
                }
            }
        }
        if(fresh!=0)return -1;

        return t;
    }
};