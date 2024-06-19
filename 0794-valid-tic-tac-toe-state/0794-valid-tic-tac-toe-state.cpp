class Solution {
public:
    bool isWin(vector<string>& board, char c) {
        for (int i = 0; i < 3; i++) {
            // Check rows
            if (board[i][0] == c && board[i][1] == c && board[i][2] == c) {
                return true;
            }
            // Check columns
            if (board[0][i] == c && board[1][i] == c && board[2][i] == c) {
                return true;
            }
        }
        // Check main diagonal
        if (board[0][0] == c && board[1][1] == c && board[2][2] == c) {
            return true;
        }
        // Check anti-diagonal
        if (board[0][2] == c && board[1][1] == c && board[2][0] == c) {
            return true;
        }
        return false;
    }
    
    bool validTicTacToe(vector<string>& board) {
        int nx = 0, no = 0;
        
        // Count the number of 'X's and 'O's
        for (int i = 0; i < 3; i++) {
            for (auto c : board[i]) {
                if (c == 'X') nx++;
                else if (c == 'O') no++;
            }
        }
        
        // Rule 1: Check the count of 'X' and 'O'
        if (nx != no && nx != no + 1) return false;
        
        // Rule 2: If 'X' wins, there should be one more 'X' than 'O'
        if (isWin(board, 'X') && nx != no + 1) return false;
        
        // Rule 3: If 'O' wins, there should be an equal number of 'X' and 'O'
        if (isWin(board, 'O') && nx != no) return false;
        
        // All checks passed
        return true;
    }
};
