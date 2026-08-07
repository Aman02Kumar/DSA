class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& mat,
             vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        mat[i][j] = 'p';

        int n = mat.size();
        int m = mat[0].size();

        while (!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            int dr[] = {1, 0, -1, 0};
            int dc[] = {0, 1, 0, -1};

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nc >= 0 && nr >= 0 && nr < n && nc < m &&
                    vis[nr][nc] == 0 && mat[nr][nc] == 'O') {
                    vis[nr][nc] = 1;
                    mat[nr][nc] = 'p';
                    q.push({nr, nc});
                }
            }
        }
    }

    void solve(vector<vector<char>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Top row
        for (int j = 0; j < m; j++) {
            if (mat[0][j] == 'O')
                bfs(0, j, mat, vis);
        }

        // Left column
        for (int i = 0; i < n; i++) {
            if (mat[i][0] == 'O')
                bfs(i, 0, mat, vis);
        }

        // Bottom row
        for (int j = 0; j < m; j++) {
            if (mat[n - 1][j] == 'O')
                bfs(n - 1, j, mat, vis);
        }

        // Right column
        for (int i = 0; i < n; i++) {
            if (mat[i][m - 1] == 'O')
                bfs(i, m - 1, mat, vis);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 'O')
                    mat[i][j] = 'X';
                if (mat[i][j] == 'p')
                    mat[i][j] = 'O';
            }
        }
    }
};