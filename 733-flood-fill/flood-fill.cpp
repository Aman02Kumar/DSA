class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, vector<vector<int>>& ans, vector<vector<int>>& visit, int color) {
        ans[sr][sc] = newColor;
        visit[sr][sc] = 1;

        // Direction vectors for up, right, down, left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        int rows = image.size();
        int cols = image[0].size();

        for (int i = 0; i < 4; i++) {
            int nr = sr + dr[i];
            int nc = sc + dc[i];

            // Check for valid cell and the color condition
            if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && !visit[nr][nc] && image[nr][nc] == color) {
                dfs(image, nr, nc, newColor, ans, visit, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows = image.size();
        int cols = image[0].size();

        // Initialize ans and visit arrays
        vector<vector<int>> ans = image;
        vector<vector<int>> visit(rows, vector<int>(cols, 0));
        int color = image[sr][sc];

        // If the starting pixel already has the new color, return the image
        if (color == newColor) {
            return image;
        }

        dfs(image, sr, sc, newColor, ans, visit, color);
        return ans;
    }
};
