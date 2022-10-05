class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int firstZeroCol = 1;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < rows; i++){
            if (matrix[i][0] == 0)  firstZeroCol = 0;
            for (int j = 1; j < cols; j++){
                if (matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = rows - 1; i >= 0; i--){
            for (int j = cols - 1; j >= 1; j--){
                if (matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
            if (firstZeroCol == 0)  matrix[i][0] = 0;
        }
        return;
    }
};
