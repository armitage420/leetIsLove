class Solution {
public:
    void helper(vector<vector<string>>& res, vector<string>& board, vector<bool>& rowhash, vector<bool>& primarydiaghash, vector<bool>& otherdiaghash, int n, int col){
        
        if(col == n){
            res.push_back(board);
            return;
        }
        
        for(int row=0; row<n; row++){
            if(!rowhash[row] && !primarydiaghash[n-1+col-row] && !otherdiaghash[row+col]){
                
                board[row][col] = 'Q';
                rowhash[row] = true;
                primarydiaghash[n-1+col-row] = true;
                otherdiaghash[row+col] = true;
                
                helper(res, board, rowhash, primarydiaghash, otherdiaghash, n, col+1);
                
                board[row][col] = '.';
                rowhash[row] = false;
                primarydiaghash[n-1+col-row] = false;
                otherdiaghash[row+col] = false;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<bool> rowhash(n, false);
        vector<bool> primarydiaghash(2*n-1, false);
        vector<bool> otherdiaghash(2*n-1, false);
        
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n, '.');
        
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        
        helper(res, board, rowhash, primarydiaghash, otherdiaghash, n, 0);
        return res;
    }
};