class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_size = matrix.size(), col_size = matrix[0].size();
        int r=0, c=col_size - 1;
        
        while(c >= 0 && r < row_size){
            if(matrix[r][c] == target)
                return true;
            else if (matrix[r][c] < target)
                r++;
            else 
                c--;
        }
        
        return false;
    }
};