class Solution {
public:
    
    int getLiveNeighbours(vector<vector<int>> &copy, int i, int j, int m, int n){
        int liveNeighbours = 0;
        
        if(i > 0 && copy[i-1][j] == 1) liveNeighbours++;
        if(i < n-1 && copy[i+1][j] == 1) liveNeighbours++;
        if(j > 0 && copy[i][j-1] == 1) liveNeighbours++;
        if(j < m-1 && copy[i][j+1] == 1) liveNeighbours++;
        if(i > 0 && j > 0 && copy[i-1][j-1] == 1) liveNeighbours++;
        if(i > 0 && j < m-1 && copy[i-1][j+1] == 1) liveNeighbours++;
        if(i < n-1 && j > 0 && copy[i+1][j-1] == 1) liveNeighbours++;
        if(i < n-1 && j < m-1 && copy[i+1][j+1] == 1) liveNeighbours++;
        
        return liveNeighbours;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> copy = board;
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int liveNeighbours = getLiveNeighbours(copy, i, j, m, n);
                
                if(board[i][j] == 0){
                    if(liveNeighbours == 3){
                        board[i][j] = 1;
                    }
                }
                else{
                    if(liveNeighbours < 2 || liveNeighbours > 3){
                        board[i][j] = 0;
                    }
                }
            }
        }

    }
};