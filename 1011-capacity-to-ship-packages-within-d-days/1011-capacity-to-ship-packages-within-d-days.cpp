class Solution {
public:
    
    bool feasible(vector<int> &weights, int capacity, int days){
        int daysNeeded = 1, currentLoad = 0;
        
        for(int it: weights){
            currentLoad += it;
            if(currentLoad > capacity){
                daysNeeded++;
                currentLoad = it;
            }
        }
        
        return daysNeeded <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int totalWeight = accumulate(weights.begin(), weights.end(), 0);
        int maxWeight = 0;
        
        for(int it: weights){
            maxWeight = max(maxWeight, it);
        }
        
        int low = maxWeight, high = totalWeight;
        while(high - low > 0){
            int mid = (low + high)/2;
            
            if(feasible(weights, mid, days)) high = mid;
            else low = mid+1;
        }
        return low;
    }
};