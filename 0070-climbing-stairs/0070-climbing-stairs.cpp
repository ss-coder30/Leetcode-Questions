class Solution {
public:
    
    int helper(int i, int n, vector<int>& dp){
        if(i == n) return 1;
        if(i > n) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        return dp[i] = helper(i+1, n, dp) + helper(i+2, n, dp);
    }
    
    int climbStairs(int n) {
        
        // top down approach
        
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        vector<int> dp(n+1, -1);
        
        int ans = helper(0, n, dp);
        
        return ans;
    }
};