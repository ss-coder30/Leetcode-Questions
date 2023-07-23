class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int n = candies.size();
        
        int maxCandies = 0;
        for(int i = 0; i<n; i++){
            if(candies[i] >= maxCandies){
                maxCandies = candies[i];
            }
        }
        
        for(int i = 0; i<n; i++){
            if(candies[i] + extraCandies >= maxCandies){
                bool result = true;
                ans.push_back(result);
            }
            else{
                bool result = false;
                ans.push_back(result);
            }
            
        }
        return ans;
    }
};