class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int firstRow = 0, colSize = matrix[0].size(), firstCol = 0, rowSize = matrix.size();
        
        for(int col = 0; col < colSize; col++){
            if(matrix[0][col] == 0){
                firstRow = 1;
                break;
            }
        }
        
        for(int row=0; row < rowSize; row++){
            if(matrix[row][0] == 0){
                firstCol = 1;
                break;
            }
        }
        
        for(int row=0; row<rowSize; row++){
            for(int col=0; col<colSize; col++){
                if(matrix[row][col] == 0){
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }
        
        for(int col=1; col<colSize; col++){
            if(matrix[0][col] == 0){
                for(int row=1; row<rowSize; row++){
                    matrix[row][col] = 0;
                }
            }
        }
        
        for(int row=1; row<rowSize; row++){
            if(matrix[row][0] == 0){
                for(int col=1; col<colSize; col++){
                    matrix[row][col] = 0;
                }
            }
        }
        
        if(firstRow == 1){
            for(int col=1; col<colSize; col++){
                matrix[0][col] = 0;
            }
        }
        
        if(firstCol == 1){
            for(int row=1; row<rowSize; row++){
                matrix[row][0] = 0;
            }
        }
    }
};