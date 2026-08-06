class Solution {
public:

    void bfs(int r , int c , vector<vector<char>>& grid, vector<vector<int>>& vis){

        queue<pair<int,int>> q;
        q.push({r,c});
        vis[r][c]= 1;
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){

            int rr = q.front().first;
            int cc = q.front().second;

            q.pop();
            int dr[] = {1,0,-1,0};
            int dc[] = {0,1,0,-1};
            for(int i = 0 ; i<4;i++){
                int nr = rr + dr[i];
                int nc = cc + dc[i];

                if(nr >=0 && nr <n && nc >=0 && nc <m && grid[nr][nc]=='1' && vis[nr][nc]==0 ){

                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0 ;

        for(int i = 0 ; i < n ; i++){
            for(int j  = 0 ; j< m;j++){

                if(vis[i][j]==0 && grid[i][j] == '1'){
    
                    bfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;

        
    }
};