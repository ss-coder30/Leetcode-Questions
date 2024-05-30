class Solution {
public:
    
    long long noOf5(long long n){
        long long ans = 0;
        long long x = 5;
        
        while(x <= n){
            ans += n/x;
            x *= 5;
        }
        
        return ans;
    }
    
    int preimageSizeFZF(int k) {
        
        long long low = 0;
        long long high = LONG_MAX;
        
        while(low <= high){
            long long mid = low + (high - low)/2;
            
            long long x = noOf5(mid);
            
            if(x == k) return 5;
            
            else if(x > k) high = mid-1;
            
            else low = mid+1;
        }
        
        return 0;
    }
};