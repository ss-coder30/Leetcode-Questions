class Solution {
public:
    
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftRow, vector<int>& upperDiag, vector<int>& lowerDiag, int n){
        
        // base case
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row<n; row++){
            
            // if previous queens are not present in same rows and diagonals
            if(leftRow[row] == 0 && lowerDiag[col + row] == 0 && upperDiag[n-1 + col - row] == 0){
                
                // marking row and diag hash vectors
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiag[col + row] = 1;
                upperDiag[n-1 + col - row] = 1;
                
                // calling recursion
                solve(col+1, board, ans, leftRow, upperDiag, lowerDiag, n);
                
                // backtracking
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiag[col + row] = 0;
                upperDiag[n-1 + col - row] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        
        for(int i = 0; i<n; i++){
            board[i] = s;
        }
        
        vector<int> leftRow(n, 0);
        vector<int> upperDiag(2*n-1, 0);
        vector<int> lowerDiag(2*n-1, 0);
        
        solve(0, board, ans, leftRow, upperDiag, lowerDiag, n);
        
        return ans;
    }
};