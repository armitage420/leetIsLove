class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char c){
        for(int i=0; i<9; i++){
            if(board[i][col] == c){
                return false;
            }
            
            if(board[row][i] == c){
                return false;
            }
            
            if(board[3*(row/3) + i/3][3*(col/3)+i%3] == c){
                return false;
            }
        }
        
        return true;
    }
    
    bool helper(vector<vector<char>>& board){
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                
                if(board[i][j] == '.'){
                    
                    for(char ch='1'; ch<='9'; ch++){
                        if(isSafe(board, i, j, ch)){
                            board[i][j] = ch;
                            
                            if(helper(board)){
                                return true;
                            }else{
                                board[i][j] ='.';
                            }
                        }
                    }
                    
                    // here after the whole sudoku is filled, it will go to recursion and then it wont be able to find 
                    // any value that is '.' and then it wont get into the if condition and hence not return a false
                    return false; // (yes, this is inside if condition)
                }

            }
        }
        
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};