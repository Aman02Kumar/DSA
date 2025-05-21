class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int col_zero = 1;
        // Take first row and col as the row or column to keep track of the zero inside
        // the smaller matrix
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j != 0){
                        matrix[0][j] = 0;
                    }else{
                        col_zero = 0;
                    }
                }
            }
        }
        // Now, according to the marked zeroth row or column assign zero to rest of the 
        // column or row
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // now, check of the first row of the matrix is zero
        if(matrix[0][0] == 0){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }
        if(col_zero == 0){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};