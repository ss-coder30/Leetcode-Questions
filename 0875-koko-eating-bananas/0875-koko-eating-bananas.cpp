class Solution {
public:
    
    int maxElement(vector<int>& a){
        int maxi = 0;
        
        for(int i = 0; i<a.size(); i++){
            maxi = max(maxi, a[i]);
        }
        
        return maxi;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1, high = maxElement(piles);
        int ans = 0;
        
        while(low < high){
            int mid = low + (high - low)/2;
            
            long long time = 0;
            for(int pile: piles){
                time += (pile + mid - 1)/mid;
            }
            
            if((int)time <= h){
                
                high = mid;
            }
            else {
                low = mid+1;
            }
        }
        
        return high;
    }
};