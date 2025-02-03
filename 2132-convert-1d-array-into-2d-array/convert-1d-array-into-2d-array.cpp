class Solution {
public:
   vector<vector<int>>construct2DArray(vector<int>& original, int m, int n) {
        // Check if the size of the original array matches the required size of the 2D array
        if (original.size() != m * n) 
            return {}; // Return empty if the sizes don't match

        vector<vector<int>> d2(m, vector<int>(n));  // Initialize the 2D array without default values
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                d2[i][j] = original[i * n + j];  // Copy elements from original to 2D array
            }
        }

        return d2;
    }
};
