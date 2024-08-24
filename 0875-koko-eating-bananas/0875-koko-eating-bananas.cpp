class Solution {
public:
    
    int maxElement(vector<int>& a){
        int maxi = INT_MIN;
        
        for(int i = 0; i<a.size(); i++){
            maxi = max(maxi, a[i]);
        }
        
        return maxi;
    }
    
    int calculateHours(vector<int>& a, int hourly){
        long long totalHours = 0;
        
        for(int i = 0; i<a.size(); i++){
            totalHours += (a[i] + hourly - 1)/ hourly;
        }
        
        return (int)totalHours;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1, high = maxElement(piles);
        
        while(low < high){
            int mid = low + (high - low)/2;
            
            int time = calculateHours(piles, mid);
            
            if(time <= h){
                high = mid;
            }
            
            else {
                low = mid+1;
            }
        }
        
        return high;
    }
};