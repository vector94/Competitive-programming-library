class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int left = 0, right = n - 1; left < right; left++, right--){
            int up = left, down = right;
            for (int i = 0; i < right - left; i++){
                swap(matrix[down - i][left], matrix[up][left + i]);
                swap(matrix[down][right - i], matrix[down - i][left]);
                swap(matrix[up + i][right], matrix[down][right - i]);
            }
        }
        return;
    }
};
