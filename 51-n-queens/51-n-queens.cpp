class Solution {
public:
    bool isSafe(vector<string>& board, int n, int row, int col){
        int row1 = row;
        int col1 = col;
        
        while(row >=0 && col >=0){
            if(board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        
        row = row1;
        col = col1;
        
        while(col >= 0){
            if(board[row][col]  == 'Q')
                return false;
            col--;
        }
        
        col = col1;
        
        while(row < n && col >= 0){
            if(board[row][col]  == 'Q')
                return false;
            row++;
            col--;
        }
        
        return true;
    }
    
    void helper(vector<vector<string>>& res, vector<string>& board, int n, int col){
        if(col == n){
            res.push_back(board);
            return;
        }
        
        for(int row=0; row<n; row++){
            if(isSafe(board, n, row, col)){
                board[row][col] = 'Q';
                helper(res, board, n, col+1);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n, '.');
        
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        
        helper(res, board, n, 0);
        return res;
    }
};