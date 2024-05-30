class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(costs.begin(), costs.end());
        
        int count = 0, totalCost = 0;
        
        for(int i = 0; i<costs.size(); i++){
            
            totalCost += costs[i];
            
            if(totalCost > coins) break;
            
            else count++;
        }
        
        return count;
        
    }
};