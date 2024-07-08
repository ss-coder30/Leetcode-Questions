class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        int vis[n][m];
        
        // marking all initial rotting oranges in vis array
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else vis[i][j] = 0;
            }
        }
        
        // creating delta row and col array to visit neighbouring oranges
        int maxTime = 0;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            maxTime = max(maxTime, time);
            q.pop();
            
            // visiting neighbours
            for(int i = 0; i<4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && 
                  vis[nRow][nCol] != 2 && grid[nRow][nCol] == 1){
                    q.push({{nRow, nCol}, time+1});
                    vis[nRow][nCol] = 2;
                }
            }
        }
        
        // check to see if all fresh are converted to rotten
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return maxTime;
    }
};