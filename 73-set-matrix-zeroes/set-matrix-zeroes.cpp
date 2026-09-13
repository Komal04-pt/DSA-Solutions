class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<bool> rowZero(row, false);
        vector<bool> colZero(col, false);

        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(matrix[r][c]==0){
                    rowZero[r] = true;
                    colZero[c] = true;
                }
            }
        }

        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(rowZero[r] || colZero[c]){
                    matrix[r][c]=0;
                }
            }
        }
    }
};