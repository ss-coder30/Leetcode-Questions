class Solution {
public:
    int climbStairs(int n) {
        
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        vector<int> dp(n+1);
        
        dp[n] = 1;
        
        for(int i = n-1; i>=0; i--){
            dp[i] = dp[i+1];
            
            if(i+2 <= n){
                dp[i] += dp[i+2];
            }
        }
        
        return dp[0];
    }
};