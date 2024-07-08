class Solution {
    
private:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i = 0; i<4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                
                if(nRow < n && nRow >= 0 && nCol < m && nCol >= 0 && grid[nRow][nCol] == '1' && !vis[nRow][nCol]){
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }
        
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int islands = 0;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    islands++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        
        return islands;
    }
};