class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int maxWealth = 0;
        int m = accounts.size();
        
        for(int i = 0; i<m; i++){
            int sum = 0;
            
            int n = accounts[i].size();
            for(int j = 0; j<n; j++){
                
                sum += accounts[i][j];
                
                if(sum >= maxWealth){
                    maxWealth = sum;
                }
            }
        }
        return maxWealth;
    }
};