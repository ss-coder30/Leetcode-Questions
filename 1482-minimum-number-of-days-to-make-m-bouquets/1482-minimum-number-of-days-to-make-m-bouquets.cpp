class Solution {
public:
    
    bool isPossible(vector<int>& a, int day, int m, int k){
        int count = 0, bouquets = 0;
        
        for(int i = 0; i<a.size(); i++){
            if(a[i] <= day){
                count++;
            }
            else {
                bouquets += count/k;
                count = 0;
            }
        }
        
        bouquets += count/k;
        
        return (bouquets >= m);
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        long long totalFlowers = m * 1ll * k * 1ll;
        
        // impossible case - flowers < needed for bouquets
        if(n < totalFlowers) return -1;
        
        // getting range
        int maxDay = INT_MIN, minDay = INT_MAX;
        
        for(int i = 0; i<n; i++){
            maxDay = max(maxDay, bloomDay[i]);
            minDay = min(minDay, bloomDay[i]);
        }
        
        // applying binary search
        int low = minDay, high = maxDay;
        int ans = -1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(isPossible(bloomDay, mid, m, k)){
                high = mid-1;
                ans = mid;
            }
            else {
                low = mid+1;
            }
        }
        
        return ans;
    }
};