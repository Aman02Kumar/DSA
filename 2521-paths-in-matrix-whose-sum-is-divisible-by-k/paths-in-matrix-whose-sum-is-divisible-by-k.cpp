class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, 0)));
        dp[0][0][grid[0][0] % k] = 1;
        
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                for (int mod = 0; mod < k; ++mod) {
                    if (j > 0) {
                        dp[i][j][(mod + grid[i][j]) % k] += dp[i][j - 1][mod] % 1000000007;
                    }
                    if (i > 0) {
                        dp[i][j][(mod + grid[i][j]) % k] += dp[i - 1][j][mod] % 1000000007;
                    }
                }
            }
        }
        return dp[n - 1][m - 1][0] % 1000000007;
    }
};